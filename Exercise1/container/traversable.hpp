#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

#include <functional>
#include "testable.hpp"

namespace lasd
{
  template <typename Data>
  class TraversableContainer : virtual public TestableContainer<Data>
  {

  public:
    virtual ~TraversableContainer() = default;

    TraversableContainer &operator=(const TraversableContainer &) = delete;

    TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;

    bool operator==(const TraversableContainer &) const noexcept = delete;

    bool operator!=(const TraversableContainer &) const noexcept = delete;

    using TraverseFun = std::function<void(const Data &)>;
    virtual void Traverse(const TraverseFun func) const = 0;

    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;
    template <typename Accumulator>
    inline Accumulator Fold(FoldFun<Accumulator> func, Accumulator acc) const;

    inline bool Exists(const Data &data) const noexcept override;
  };

  template <typename Data>
  class PreOrderTraversableContainer : virtual public TraversableContainer<Data>
  {

  public:
    virtual ~PreOrderTraversableContainer() = default;

    PreOrderTraversableContainer &operator=(const PreOrderTraversableContainer &) = delete;

    PreOrderTraversableContainer &operator=(PreOrderTraversableContainer &&) noexcept = delete;

    bool operator==(const PreOrderTraversableContainer &) const noexcept = delete;

    bool operator!=(const PreOrderTraversableContainer &) const noexcept = delete;

    using typename TraversableContainer<Data>::TraverseFun;
    virtual void PreOrderTraverse(const TraverseFun func) const = 0;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
    template <typename Accumulator>
    inline Accumulator PreOrderFold(FoldFun<Accumulator> func, Accumulator acc) const;

    inline void Traverse(TraverseFun func) const override;
  };

  template <typename Data>
  class PostOrderTraversableContainer : virtual public TraversableContainer<Data>
  {

  public:
    virtual ~PostOrderTraversableContainer() = default;

    PostOrderTraversableContainer &operator=(const PostOrderTraversableContainer &) const noexcept = delete;

    PostOrderTraversableContainer &operator=(PostOrderTraversableContainer &&) noexcept = delete;

    bool operator==(const PostOrderTraversableContainer &) const noexcept = delete;

    bool operator!=(const PostOrderTraversableContainer &) const noexcept = delete;

    using typename TraversableContainer<Data>::TraverseFun;
    virtual void PostOrderTraverse(const TraverseFun func) const = 0;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
    template <typename Accumulator>
    inline Accumulator PostOrderFold(FoldFun<Accumulator> func, Accumulator acc) const;
    inline void Traverse(const TraverseFun func) const override;
  };

}

#include "traversable.cpp"

#endif
