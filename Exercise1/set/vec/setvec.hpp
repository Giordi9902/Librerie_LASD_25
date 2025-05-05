
#ifndef SETVEC_HPP
#define SETVEC_HPP

#include "../set.hpp"
#include "../../vector/vector.hpp"

#define INIT_SIZE 16
#define INCREASE_FACTOR 2
#define REDUCE_FACTOR 2

namespace lasd
{
  template <typename Data>
  class SetVec : public virtual Set<Data>,
                 public virtual ResizableContainer

  {

  protected:
    using Container::size;
    Vector<Data> vector;
    ulong head = 0; // min element index
    ulong tail = 0; // max element index
    ulong totalElems = 0;

  public:
    SetVec();
    SetVec(const TraversableContainer<Data> &);
    SetVec(MappableContainer<Data> &&) noexcept;
    SetVec(const SetVec<Data> &);
    SetVec(SetVec<Data> &&);
    virtual ~SetVec() = default;
    SetVec<Data> &operator=(const SetVec<Data> &);
    SetVec<Data> &operator=(SetVec<Data> &&);
    inline bool operator==(const SetVec<Data> &) const noexcept;
    inline bool operator!=(const SetVec<Data> &) const noexcept;
    const Data& Min() const override;
    const Data& MinNRemove() override;
    void RemoveMin() override;
    const Data& Max() const override;
    const Data& MaxNRemove() override;
    void RemoveMax() override;
    const Data& Predecessor(const Data &) const override;
    const Data& PredecessorNRemove(const Data &) override;
    void RemovePredecessor(const Data &) override;
    const Data& Successor(const Data &) const override;
    const Data& SuccessorNRemove(const Data &) override;
    void RemoveSuccessor(const Data &) override;
    bool Insert(const Data &) override;
    bool Insert(Data &&) override;
    bool Remove(const Data &) override;
    const Data &operator[](ulong) const override;
    bool Exists(const Data &) const noexcept override;
    void Clear() override;

  protected:
    void Resize(const ulong) override;
    ulong PredecessorIndex(const Data&) const;
    ulong SuccessorIndex(const Data&) const;
  };

}

#include "setvec.cpp"

#endif
