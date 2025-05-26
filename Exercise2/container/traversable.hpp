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
    virtual void Traverse(const TraverseFun) const = 0;

    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

    template <typename Accumulator>
    Accumulator Fold(const FoldFun<Accumulator>, Accumulator) const;

    bool Exists(const Data &data) const noexcept override;
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
    virtual void PreOrderTraverse(const TraverseFun) const = 0;

    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    void Traverse(const TraverseFun) const override;

    template <typename Accumulator>
    Accumulator PreOrderFold(const FoldFun<Accumulator>, Accumulator) const;
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

    void Traverse(const TraverseFun func) const override;

    template <typename Accumulator>
    Accumulator PostOrderFold(const FoldFun<Accumulator> func, Accumulator acc) const;
  };

}

#include "traversable.cpp"

#endif
