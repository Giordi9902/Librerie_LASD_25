
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

#include "../heap.hpp"
#include "../../vector/vector.hpp"

namespace lasd
{

    template <typename Data>
    class HeapVec : virtual public Heap<Data>, public SortableVector<Data>
    {

    protected:
        using Container::size;
        using SortableVector<Data>::elements;

    public:

        HeapVec() = default;
        HeapVec(const TraversableContainer<Data> &);
        HeapVec(MappableContainer<Data> &&);
        HeapVec(const HeapVec<Data> &);
        HeapVec(HeapVec<Data> &&) noexcept;
        virtual ~HeapVec() = default;
        HeapVec<Data> &operator=(const HeapVec<Data> &);
        HeapVec<Data> &operator=(HeapVec<Data> &&) noexcept;

        bool operator==(const HeapVec<Data> &) const noexcept;
        bool operator!=(const HeapVec<Data> &) const noexcept;

        bool IsHeap() const noexcept override;

        void Heapify() noexcept override;

        void Sort() { HeapSort(); };
        void Clear() override;
        //using SortableVector<Data>::operator[];

    protected:
        void HeapSort() noexcept;
        void HeapifyNode(ulong,ulong) noexcept;

        ulong Left(ulong) const;
        ulong Right(ulong) const ;
        ulong Parent(ulong) const;
    };

    /* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
