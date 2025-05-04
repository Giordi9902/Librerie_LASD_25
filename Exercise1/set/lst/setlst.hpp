
#ifndef SETLST_HPP
#define SETLST_HPP

#include "../set.hpp"
#include "../../list/list.hpp"

namespace lasd
{

  template <typename Data>
  class SetLst : public virtual Set<Data>,
                 virtual protected List<Data>
  {

  protected:
    using Container::size;
    using List<Data>::head;
    using List<Data>::tail;

  public:
    // Default constructor
    SetLst() = default;

    // Specific constructors
    SetLst(const TraversableContainer<Data> &);
    SetLst(MappableContainer<Data> &&);

    // Copy constructor
    SetLst(const SetLst<Data> &);

    // Move constructor
    SetLst(SetLst<Data> &&) noexcept;

    // Destructor
    virtual ~SetLst() = default;

    // Copy assignment
    SetLst<Data> &operator=(const SetLst<Data> &);

    // Move assignment
    SetLst<Data> &operator=(SetLst<Data> &&) noexcept;

    // Comparison operators
    bool operator==(const SetLst<Data> &) const noexcept;
    bool operator!=(const SetLst<Data> &) const noexcept;

    // Specific member functions (inherited from OrderedDictionaryContainer)

    const Data& Min() const override;
    const Data& MinNRemove() override;
    void RemoveMin() override;

    const Data &Max() const override;
    const Data& MaxNRemove() override;
    void RemoveMax() override;

    const Data &Predecessor(const Data &) const override;
    const Data &PredecessorNRemove(const Data &) override;
    void RemovePredecessor(const Data &) override;

    const Data &Successor(const Data &) const override;
    const Data &SuccessorNRemove(const Data &) override;
    void RemoveSuccessor(const Data &) override;

    // Specific member functions (inherited from DictionaryContainer)
    bool Insert(const Data &) override;
    bool Insert(Data &&) override;
    bool Remove(const Data &) override;

    // Specific member functions (inherited from LinearContainer)
    const Data &operator[](unsigned long) const override;

    // Specific member function (inherited from TestableContainer)
    using List<Data>::Exists;

    // Specific member function (inherited from ClearableContainer)
    using List<Data>::Clear;


  protected:
    // Auxiliary functions, if necessary!
  };

}

#include "setlst.cpp"

#endif
