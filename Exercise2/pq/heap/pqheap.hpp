
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

#define INIT_SIZE 16

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

namespace lasd
{

    template <typename Data>
    class PQHeap : virtual public PQ<Data>, virtual protected HeapVec<Data>
    {

    protected:
        using Container::size;
        using HeapVec<Data>::elements;
        ulong capacity;

    public:
        PQHeap() = default;
        PQHeap(const TraversableContainer<Data> &);
        PQHeap(MappableContainer<Data> &&);
        PQHeap(const PQHeap<Data> &);
        PQHeap(PQHeap<Data> &&) noexcept;
        virtual ~PQHeap() = default;
        PQHeap &operator=(const PQHeap &);
        PQHeap &operator=(PQHeap &&) noexcept;
        const Data &Tip() const override;
        void RemoveTip() override;
        Data TipNRemove() override;
        void Insert(const Data &) override;
        void Insert(Data &&) override;
        void Change(ulong, const Data &) override;
        void Change(ulong, Data &&) override;
        void Clear() override;
        using HeapVec<Data>::operator[];

    protected:
        void HeapifyUp(ulong index);
        void Resize(ulong);
        bool IsFull();
    };
}

#include "pqheap.cpp"

#endif
