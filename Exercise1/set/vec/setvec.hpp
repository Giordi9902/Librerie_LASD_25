
#ifndef SETVEC_HPP
#define SETVEC_HPP

#define INIT_SIZE 16

#include "../set.hpp"
#include "../../vector/vector.hpp"


namespace lasd
{

  template <typename Data>
  class SetVec : virtual public Set<Data>,
                 virtual protected ResizableContainer
  {

  protected:
    using Container::size;
    Vector<Data> vector;
    ulong head = 0;
    ulong tail = 0;

  public:
    // Default constructor
    SetVec();

    // Specific constructors
    SetVec(const TraversableContainer<Data> &);
    SetVec(MappableContainer<Data> &&);

    // Copy constructor
    SetVec(const SetVec<Data> &);

    // Move constructor
    SetVec(SetVec<Data> &&) noexcept;

    // Destructor
    virtual ~SetVec() = default;

    // Copy assignment
    SetVec<Data> &operator=(const SetVec<Data> &);

    // Move assignment
    SetVec<Data> &operator=(SetVec<Data> &&) noexcept;

    // Comparison operators
    bool operator==(const SetVec<Data> &) const noexcept;
    bool operator!=(const SetVec<Data> &) const noexcept;

    // Specific member functions (inherited from OrderedDictionaryContainer)
    const Data &Min() const override;
    const Data MinNRemove() override;
    void RemoveMin() override;

    const Data &Max() const override;
    const Data MaxNRemove() override;
    void RemoveMax() override;

    const Data &Predecessor(const Data &) const override;
    const Data PredecessorNRemove(const Data &) override;
    void RemovePredecessor(const Data &) override;

    const Data &Successor(const Data &) const override;
    const Data SuccessorNRemove(const Data &) override;
    void RemoveSuccessor(const Data &) override;

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data &) override;
    bool Insert(Data &&) override;
    bool Remove(const Data &) override;

    // Specific member functions (inherited from LinearContainer)
    const Data& operator[](ulong) const;

    // Specific member function (inherited from TestableContainer)
    bool Exists(const Data &) const noexcept;

    // Specific member function (inherited from ClearableContainer)
    void Clear() override;

    ulong Size() const noexcept override;

    bool Empty() const noexcept override;

    using typename TraversableContainer<Data>::TraverseFun;
    void PostOrderTraverse(const TraverseFun)const override;
    void PreOrderTraverse(const TraverseFun)const override;

  protected:
    // Auxiliary functions, if necessary!
    ulong FindInsertIndex(const Data&) const;
    ulong FindElementIndex(const Data&) const;
    void InsertAtIndex(const Data&);
    void InsertAtIndex(Data&&);
    void Resize(ulong);
    long BinarySearch(const Data&)const;
    void CheckNHalve();
    void CheckNDouble();
    void ShiftRight(ulong);
    void ShiftLeft(ulong);
  };

}

#include "setvec.cpp"

#endif
