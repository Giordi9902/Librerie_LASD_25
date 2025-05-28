
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../container/linear.hpp"
namespace lasd
{
  template <typename Data>
  class Vector : virtual public MutableLinearContainer<Data>,
                 virtual public ResizableContainer
  {

  protected:
    using Container::size;
    Data *elements = nullptr;

  public:
    Vector() = default;
    Vector(const ulong initSize)
    {
      size = initSize;
      elements = new Data[initSize]();
    };

    Vector(const TraversableContainer<Data> &);
    Vector(MappableContainer<Data> &&);
    Vector(const Vector<Data> &);
    Vector(Vector<Data> &&) noexcept;

    virtual ~Vector() { delete[] elements; };

    Vector<Data> &operator=(const Vector<Data> &);
    Vector<Data> &operator=(Vector<Data> &&) noexcept;

    bool operator==(const Vector<Data> &) const noexcept;
    bool operator!=(const Vector<Data> &) const noexcept;

    Data &operator[](ulong) override;
    Data &Front() override;
    Data &Back() override;

    const Data &operator[](ulong) const override;
    const Data &Front() const override;
    const Data &Back() const override;

    void Resize(ulong) override;

    void Clear() override;

  };

  template <typename Data>
  class SortableVector : public Vector<Data>,
                         virtual public SortableLinearContainer<Data>
  {
  protected:
    using Container::size;

  public:
    SortableVector() = default;

    inline SortableVector(const ulong s) : Vector<Data>::Vector(s) {};
    SortableVector(const TraversableContainer<Data> &con) : Vector<Data>::Vector(con) {};
    SortableVector(MappableContainer<Data> &&con) noexcept : Vector<Data>::Vector(std::move(con)) {};
    SortableVector(const SortableVector<Data> &con) : Vector<Data>::Vector(con) {};
    SortableVector(SortableVector<Data> &&con) noexcept : Vector<Data>::Vector(std::move(con)) {};

    virtual ~SortableVector() = default;

    SortableVector<Data> &operator=(const SortableVector<Data> &);
    SortableVector<Data> &operator=(SortableVector<Data> &&) noexcept;

  };

}

#include "vector.cpp"

#endif
