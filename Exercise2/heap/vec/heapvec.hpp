
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */
#define INIT_SIZE 16

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd
{

    /* ************************************************************************** */

    template <typename Data>
    class HeapVec : virtual public Heap<Data>
    {
        // Must extend Heap<Data>,
        // Could extend SortableVector<Data>

    private:
        // ...

    protected:
        // using Container::???;
        using Container::size;
        SortableVector<Data> vector;

        // ...

    public:
        // Default constructor
        // HeapVec() specifiers;
        HeapVec();

        /* ************************************************************************ */

        // Specific constructors
        // HeapVec(argument) specifiers; // A heap obtained from a TraversableContainer
        HeapVec(const TraversableContainer<Data> &);
        // HeapVec(argument) specifiers; // A heap obtained from a MappableContainer
        HeapVec(MappableContainer<Data> &&);

        /* ************************************************************************ */

        // Copy constructor
        // HeapVec(argument) specifiers;
        HeapVec(const HeapVec<Data> &);

        // Move constructor
        // HeapVec(argument) specifiers;
        HeapVec(HeapVec<Data> &&) noexcept;

        /* ************************************************************************ */

        // Destructor
        // ~HeapVec() specifiers;
        virtual ~HeapVec() = default;

        /* ************************************************************************ */

        // Copy assignment
        // type operator=(argument) specifiers;
        HeapVec<Data> &operator=(const HeapVec<Data> &);

        // Move assignment
        // type operator=(argument) specifiers;
        HeapVec<Data> &operator=(HeapVec<Data> &&) noexcept;

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers;
        bool operator==(const HeapVec<Data> &) const noexcept;
        // type operator!=(argument) specifiers;
        bool operator!=(const HeapVec<Data> &) const noexcept;

        /* ************************************************************************ */

        // Specific member functions (inherited from Heap)

        // type IsHeap(argument) specifiers; // Override Heap member
        bool IsHeap() const noexcept override;

        // type Heapify(argument) specifiers; // Override Heap member
        void Heapify() noexcept override;
        /* ************************************************************************ */

        // Specific member function (inherited from SortableLinearContainer)

        // type Sort(argument) specifiers; // Override SortableLinearContainer member
        void Sort() { HeapSort(); };
        const Data &operator[](ulong) const;
        Data &operator[](ulong);

        /*************************************************************** */
        void Clear() noexcept override;

    protected:
        // Auxiliary functions, if necessary!
        void HeapSort() noexcept;
        void Heapify(ulong, ulong) noexcept;
    };

    /* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
