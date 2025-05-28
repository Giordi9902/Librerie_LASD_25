
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    class PQHeap : virtual public PQ<Data>
    {
        // Must extend PQ<Data>,
        // Could extend HeapVec<Data>

    private:
        // ...

    protected:
        // using Container::???;
        using Container::size;
        HeapVec<Data> heap;

        // ...

    public:
        // Default constructor
        // PQHeap() specifiers;
        PQHeap() = default;

        /* ************************************************************************ */

        // Specific constructors
        // PQHeap(argument) specifiers; // A priority queue obtained from a TraversableContainer
        PQHeap(const TraversableContainer<Data> &con) : heap(con) {size=heap.Size();}
        // PQHeap(argument) specifiers; // A priority queue obtained from a MappableContainer
        PQHeap(MappableContainer<Data> &&con) : heap(std::move(con)) {size=heap.Size();}

        /* ************************************************************************ */

        // Copy constructor
        // PQHeap(argument) specifiers;
        PQHeap(const PQHeap<Data> &pq) : heap(pq.heap) {size=heap.Size();}

        // Move constructor
        // PQHeap(argument) specifiers;
        PQHeap(PQHeap<Data> &&pq) noexcept : heap(std::move(pq.heap)) {size=heap.Size();}

        /* ************************************************************************ */

        // Destructor
        // ~PQHeap() specifiers;
        virtual ~PQHeap() = default;
        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument) specifiers;
        PQHeap<Data> &operator=(const PQHeap<Data> &);

        // Move assignment
        // type operator=(argument) specifiers;
        PQHeap<Data> &operator=(PQHeap<Data> &&pq) noexcept;

        /* ************************************************************************ */

        // Specific member functions (inherited from PQ)

        // type Tip(argument) specifiers; // Override PQ member (must throw std::length_error when empty)
        const Data &Tip() const;
        // type RemoveTip(argument) specifiers; // Override PQ member (must throw std::length_error when empty)
        void RemoveTip();
        // type TipNRemove(argument) specifiers; // Override PQ member (must throw std::length_error when empty)
        Data TipNRemove();

        // type Insert(argument) specifiers; // Override PQ member (Copy of the value)
        // type Insert(argument) specifiers; // Override PQ member (Move of the value)
        void Insert(const Data &data);
        void Insert(Data &&data);

        // type Change(argument) specifiers; // Override PQ member (Copy of the value)
        void Change(ulong, const Data &data);
        // type Change(argument) specifiers; // Override PQ member (Move of the value)
        void Change(ulong, Data &&data);

        void Clear();

        const Data &operator[](const ulong) const;

    protected:
        // Auxiliary functions, if necessary!
    };

    /* ************************************************************************** */

}

#include "pqheap.cpp"

#endif
