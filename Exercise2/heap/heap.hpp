
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Heap : public virtual SortableLinearContainer<Data>, public virtual ClearableContainer{
  // Must extend SortableLinearContainer<Data>,
  //             ClearableContainer

private:

protected:

public:

  // Destructor
  // ~Heap() specifiers
  virtual ~Heap() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  Heap<Data>& operator=(const Heap<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  Heap<Data>& operator=(Heap<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type IsHeap(argument) specifiers;
  bool IsHeap() const noexcept = 0;

  // type Heapify(argument) specifiers;
  void Heapify() noexcept = 0;

};

/* ************************************************************************** */

}

#endif
