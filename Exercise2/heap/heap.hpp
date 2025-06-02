
#ifndef HEAP_HPP
#define HEAP_HPP

#include "../container/linear.hpp"

namespace lasd
{

    template <typename Data>
    class Heap : public virtual SortableLinearContainer<Data>, public ClearableContainer
    {

    public:
        virtual ~Heap() = default;
        Heap &operator=(const Heap &) = delete;
        Heap &operator=(Heap &&) noexcept = delete;

        virtual bool IsHeap() const noexcept = 0;

        virtual void Heapify() noexcept = 0;
    };

}

#endif
