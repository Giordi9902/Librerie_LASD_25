
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class DictionaryContainer : virtual public TestableContainer<Data>
  {

  public:
    // Destructor
    virtual ~DictionaryContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    DictionaryContainer &operator=(const DictionaryContainer &) = delete;
    // Move assignment
    DictionaryContainer &operator=(DictionaryContainer &&) noexcept = delete;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const DictionaryContainer &) const noexcept = delete;
    bool operator!=(const DictionaryContainer &) const noexcept = delete;

    /* ************************************************************************ */

    // Specific member functions

    virtual bool Insert(const Data &) = 0;
    virtual bool Insert(Data &&) = 0;
    virtual bool Remove(const Data &) = 0;

    virtual inline bool InsertAll(const TraversableContainer<Data> &);
    virtual inline bool InsertAll(MappableContainer<Data> &&);
    virtual inline bool RemoveAll(const TraversableContainer<Data> &);
    virtual inline bool InsertSome(const TraversableContainer<Data> &);
    virtual inline bool InsertSome(MappableContainer<Data> &&);
    virtual inline bool RemoveSome(const TraversableContainer<Data> &);
  };

  template <typename Data>
  class OrderedDictionaryContainer : virtual public DictionaryContainer<Data>
  {

  public:
    // Destructor
    virtual ~OrderedDictionaryContainer() = default;

    // Copy assignment
    OrderedDictionaryContainer &operator=(const OrderedDictionaryContainer &) const = delete;
    OrderedDictionaryContainer &operator=(OrderedDictionaryContainer &&) noexcept = delete;

    // Comparison operators
    bool operator==(const OrderedDictionaryContainer &) const noexcept = delete;
    bool operator!=(const OrderedDictionaryContainer &) const noexcept = delete;

    // Specific member functions

    // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
    virtual const Data& Min() const = 0;
    // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
    virtual Data MinNRemove() = 0;
    // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
    virtual void RemoveMin() = 0;

    // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
    virtual const Data& Max() const = 0;
    // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
    virtual Data MaxNRemove() = 0;
    // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
    virtual void RemoveMax() = 0;

    // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
    virtual const Data& Predecessor(const Data &) const = 0;
    // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
    virtual Data PredecessorNRemove(const Data &) = 0;
    // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
    virtual void RemovePredecessor(const Data &) = 0;

    // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
    virtual const Data& Successor(const Data &) const = 0;
    // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
    virtual Data SuccessorNRemove(const Data &) = 0;
    // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
    virtual void RemoveSuccessor(const Data &) = 0;
  };

}

#include "dictionary.cpp"

#endif
