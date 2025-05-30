
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */
#define INIT_SIZE 16

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    class PQHeap : virtual public PQ<Data>, virtual public HeapVec<Data>
    {

    protected:
        using Container::size;
        using HeapVec<Data>::elements;
        ulong capacity;

    public:
        // Default constructor
        PQHeap() = default;

        // Specific constructors
        PQHeap(const TraversableContainer<Data> &);
        PQHeap(MappableContainer<Data> &&);

        // Copy constructor
        PQHeap(const PQHeap<Data> &);

        // Move constructor
        PQHeap(PQHeap<Data> &&) noexcept;

        // Destructor
        virtual ~PQHeap() = default;

        /* ************************************************************************ */

        // Copy assignment
        PQHeap &operator=(const PQHeap &);

        // Move assignment
        PQHeap &operator=(PQHeap &&) noexcept;

        /* ************************************************************************ */

        const Data &Tip() const override; // Override PQ member (must throw std::length_error when empty)
        void RemoveTip() override;        // Override PQ member (must throw std::length_error when empty)
        Data TipNRemove() override;       // Override PQ member (must throw std::length_error when empty)

        void Insert(const Data &) override;
        void Insert(Data &&) override;

        void Change(ulong, const Data &) override;
        void Change(ulong, Data &&) override;

        // Specific member functions (inherited from PQ)

        void Clear() override;

    protected:
        void HeapifyUp(ulong index);
        void Resize(ulong);
        bool IsFull();
    };
}

#include "pqheap.cpp"

#endif
