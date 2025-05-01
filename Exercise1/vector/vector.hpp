
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
    Vector(const unsigned long initSize)
    {
      size = initSize;
      elements = new Data[initSize]();
    };
    Vector(const TraversableContainer<Data> &);
    Vector(MappableContainer<Data> &&);
    inline Vector(const Vector<Data> &);
    inline Vector(Vector<Data> &&) noexcept;
    virtual ~Vector() { delete[] elements; };
    inline Vector<Data> &operator=(const Vector<Data> &);
    inline Vector<Data> &operator=(Vector<Data> &&) noexcept;
    bool operator==(const Vector<Data> &) const noexcept;
    inline bool operator!=(const Vector<Data> &) const noexcept;
    inline Data &operator[](unsigned long) override;
    inline Data &Front() override;
    inline Data &Back() override;
    inline const Data &operator[](unsigned long) const override;
    inline const Data &Front() const override;
    inline const Data &Back() const override;
    void Resize(unsigned long) override;
    inline void Clear() override;
  };

  template <typename Data>
  class SortableVector : virtual public Vector<Data> ,
                         virtual public SortableLinearContainer<Data>
  {
  protected:
    using Container::size;

  public:
    SortableVector() = default;
    inline SortableVector(const unsigned long s) : Vector<Data>::Vector(s) {};
    inline SortableVector(const TraversableContainer<Data> &con) : Vector<Data>::Vector(con) {};
    inline SortableVector(MappableContainer<Data> &&con) : Vector<Data>::Vector(std::move(con)) {};
    inline SortableVector(const SortableVector<Data> &con) : Vector<Data>::Vector(con) {};
    inline SortableVector(SortableVector<Data> &&con) noexcept : Vector<Data>::Vector(std::move(con)) {};
    virtual ~SortableVector() = default;
    inline SortableVector<Data> &operator=(const SortableVector<Data> &);
    inline SortableVector<Data> &operator=(SortableVector<Data> &&) noexcept;

  };

}

#include "vector.cpp"

#endif
