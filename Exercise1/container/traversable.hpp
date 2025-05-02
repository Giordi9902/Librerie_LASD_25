
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
    // Destructor
    virtual ~TraversableContainer() = default;

    // Copy assignment
    TraversableContainer &operator=(const TraversableContainer &) = delete;
    // Move assignment
    TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;

    // Comparison operators
    bool operator==(const TraversableContainer &) const noexcept = delete;
    bool operator!=(const TraversableContainer &) const noexcept = delete;

    // Specific member function
    using TraverseFun = std::function<void(const Data &)>;
    virtual void Traverse(const TraverseFun) const = 0;
    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

    template <typename Accumulator>
    inline Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;

    inline bool Exists(const Data &) const noexcept override;
  };

  template <typename Data>
  class PreOrderTraversableContainer : virtual public TraversableContainer<Data>
  {

  public:
    // Destructor
    virtual ~PreOrderTraversableContainer() = default;

    // Copy and move assignment
    PreOrderTraversableContainer &operator=(const PreOrderTraversableContainer &) = delete;
    PreOrderTraversableContainer &operator=(PreOrderTraversableContainer &&) noexcept = delete;

    // Comparison operators
    bool operator==(const PreOrderTraversableContainer &) const noexcept = delete;
    bool operator!=(const PreOrderTraversableContainer &) const noexcept = delete;

    using typename TraversableContainer<Data>::TraverseFun;
    virtual void PreOrderTraverse(const TraverseFun) const = 0;
    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    template <typename Accumulator>
    inline Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

    // Specific member function (inherited from TraversableContainer)
    inline void Traverse(TraverseFun) const override;
  };

  template <typename Data>
  class PostOrderTraversableContainer : virtual public TraversableContainer<Data>
  {

  public:
    // Destructor
    virtual ~PostOrderTraversableContainer() = default;

    // Copy assignment
    PostOrderTraversableContainer &operator=(const PostOrderTraversableContainer &) const noexcept = delete;
    // Move assignment
    PostOrderTraversableContainer &operator=(PostOrderTraversableContainer &&) noexcept = delete;

    // Comparison operators
    bool operator==(const PostOrderTraversableContainer &) const noexcept = delete;
    bool operator!=(const PostOrderTraversableContainer &) const noexcept = delete;

    // Specific member function
    using typename TraversableContainer<Data>::TraverseFun;
    virtual void PostOrderTraverse(const TraverseFun) const = 0;
    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    template <typename Accumulator>
    inline Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;
    inline void Traverse(const TraverseFun) const override;
    // Specific member function (inherited from TraversableContainer)
  };

}

#include "traversable.cpp"

#endif
