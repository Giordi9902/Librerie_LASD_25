#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include "testable.hpp"
#include "mappable.hpp"

namespace lasd
{


  template <typename Data>
  class DictionaryContainer : virtual public TestableContainer<Data>
  {

  public:

    virtual ~DictionaryContainer() = default;


    DictionaryContainer &operator=(const DictionaryContainer &) = delete;

    DictionaryContainer &operator=(DictionaryContainer &&) noexcept = delete;

    bool operator==(const DictionaryContainer &) const noexcept = delete;

    bool operator!=(const DictionaryContainer &) const noexcept = delete;

    virtual bool Insert(const Data &data) = 0;

    virtual bool Insert(Data &&data) = 0;

    virtual bool Remove(const Data &data) = 0;

    virtual bool InsertAll(const TraversableContainer<Data> &container);

    virtual bool InsertAll(MappableContainer<Data> &&container);

    virtual bool RemoveAll(const TraversableContainer<Data> &container);

    virtual bool InsertSome(const TraversableContainer<Data> &container);

    virtual bool InsertSome(MappableContainer<Data> &&container);

    virtual bool RemoveSome(const TraversableContainer<Data> &container);
  };
  template <typename Data>
  class OrderedDictionaryContainer : virtual public DictionaryContainer<Data>
  {

  public:

    virtual ~OrderedDictionaryContainer() = default;

    OrderedDictionaryContainer &operator=(const OrderedDictionaryContainer &) const = delete;

    OrderedDictionaryContainer &operator=(OrderedDictionaryContainer &&) noexcept = delete;

    bool operator==(const OrderedDictionaryContainer &) const noexcept = delete;

    bool operator!=(const OrderedDictionaryContainer &) const noexcept = delete;

    virtual const Data &Min() const = 0;
    virtual const  Data MinNRemove() = 0;
    virtual void RemoveMin() = 0;

    virtual const Data& Max() const = 0;
    virtual const Data MaxNRemove() = 0;
    virtual void RemoveMax() = 0;

    virtual const Data& Predecessor(const Data &) const = 0;
    virtual const Data PredecessorNRemove(const Data&) = 0;    virtual void RemovePredecessor(const Data&) = 0;

    virtual const Data& Successor(const Data &) const = 0;
    virtual const Data SuccessorNRemove(const Data&) = 0;
    virtual void RemoveSuccessor(const Data&) = 0;

  };

}

#include "dictionary.cpp"

#endif
