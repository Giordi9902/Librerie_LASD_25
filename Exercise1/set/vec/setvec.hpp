
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec : public virtual Set<Data>,
              public virtual ResizableContainer
  {
  // Must extend Set<Data>,
  //             ResizableContainer

private:

  // ...

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  // SetVec() specifiers;
  SetVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // SetVec(argument) specifiers; // A set obtained from a TraversableContainer
  SetVec(const TraversableContainer<Data>&);
  // SetVec(argument) specifiers; // A set obtained from a MappableContainer
  SetVec(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // SetVec(argument) specifiers;
  SetVec(const SetVec<Data>&);

  // Move constructor
  // SetVec(argument) specifiers;
  SetVec(SetVec<Data>&&);

  /* ************************************************************************ */

  // Destructor
  // ~SetVec() specifiers;
  virtual ~SetVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  SetVec<Data> &operator=(const SetVec<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  SetVec<Data> &operator=(SetVec<Data>&&);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const SetVec<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const SetVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  // type Min(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  const Data& Min() const;
  // type MinNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data& MinNRemove();
  // type RemoveMin(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMin();
  // type Max(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  const Data& Max() const;
  // type MaxNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data& MaxNRemove();
  // type RemoveMax(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMax();

  // type Predecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  const Data& Predecessor(const Data&) const;
  // type PredecessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  const Data& PredecessorNRemove(const Data&);
  // type RemovePredecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&);

  // type Successor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  const Data& Successor(const Data&) const;
  // type SuccessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  const Data& SuccessorNRemove(const Data&);
  // type RemoveSuccessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (copy of the value)
  bool Insert(const Data&);
  // type Insert(argument) specifiers; // Override DictionaryContainer member (move of the value)
  bool Insert(Data&&);
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Remove(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)
  const Data& operator[](unsigned long) const;

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear();

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
