
#ifndef SETVEC_HPP
#define SETVEC_HPP
#define INIT_SIZE 16

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class SetVec : virtual public Set<Data>, virtual public ResizableContainer
  {

  private:
    Vector<Data> vector;
    ulong head = 0;
    ulong tail = 0;
    ulong totalElements = 0;
  protected:
    using Container::size;

  public:
    // Default constructor
    // SetVec() specifiers;
    SetVec():vector(INIT_SIZE),head(0),tail(0),totalElements(0) {
      size=INIT_SIZE;
    };

    /* ************************************************************************ */

    // Specific constructors
    // SetVec(argument) specifiers; // A set obtained from a TraversableContainer
    SetVec(const TraversableContainer<Data> &);
    // SetVec(argument) specifiers; // A set obtained from a MappableContainer
    SetVec(MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    // SetVec(argument) specifiers;
    SetVec(const SetVec<Data> &);

    // Move constructor
    // SetVec(argument) specifiers;
    SetVec(SetVec<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    // ~SetVec() specifiers;
    virtual ~SetVec() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;
    SetVec<Data> &operator=(const SetVec<Data> &);

    // Move assignment
    // type operator=(argument) specifiers;
    SetVec<Data> &operator=(SetVec<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    bool operator==(const SetVec<Data> &) const noexcept;
    // type operator!=(argument) specifiers;
    bool operator!=(const SetVec<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    // type Min(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    const Data &Min() const override;
    // type MinNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    const Data MinNRemove() override;
    // type RemoveMin(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    void RemoveMin() override;

    // type Max(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    const Data &Max() const override;
    // type MaxNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    const Data MaxNRemove() override;
    // type RemoveMax(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
    void RemoveMax() override;

    // type Predecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
    const Data &Predecessor(const Data &) const override;
    // type PredecessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
    const Data PredecessorNRemove(const Data &) override;
    // type RemovePredecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
    void RemovePredecessor(const Data &) override;

    // type Successor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
    const Data &Successor(const Data &) const override;
    // type SuccessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
    const Data SuccessorNRemove(const Data &) override;
    // type RemoveSuccessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
    void RemoveSuccessor(const Data &) override;

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    // type Insert(argument) specifiers; // Override DictionaryContainer member (copy of the value)
    bool Insert(const Data &) override;
    // type Insert(argument) specifiers; // Override DictionaryContainer member (move of the value)
    bool Insert(Data &&) override;
    // type Remove(argument) specifiers; // Override DictionaryContainer member
    bool Remove(const Data &) override;

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)
    const Data& operator[](ulong) const;

    /* ************************************************************************** */

    // Specific member function (inherited from TestableContainer)

    // type Exists(argument) specifiers; // Override TestableContainer member
    bool Exists(const Data &) const noexcept;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    // type Clear() specifiers; // Override ClearableContainer member
    void Clear() override;

    void Resize(ulong);
    ulong Size() const noexcept override;

  protected:
    // Auxiliary functions, if necessary!
    ulong FindIndex(const Data &) const;
    ulong FindInsertIndex(const Data &) const;
  };

  /* ************************************************************************** */

}

#include "setvec.cpp"

#endif
