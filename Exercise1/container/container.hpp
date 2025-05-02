
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace lasd
{
  class Container
  {

  protected:
    unsigned long size = 0;

    // Default constructor
    Container() = default;

  public:
    // Destructor
    virtual ~Container() = default;

    // Copy assignment
    Container &operator=(const Container &) = delete;
    // Move assignment
    Container &operator=(Container &&) noexcept = delete;

    // Comparison operators
    bool operator==(const Container &) const noexcept = delete;
    bool operator!=(const Container &) const noexcept = delete;

    // Specific member functions
    inline virtual bool Empty() const noexcept { return 0 == size; }
    inline virtual unsigned long Size() const noexcept { return size; }
  };

  class ClearableContainer : virtual public Container
  {

  public:
    // Destructor
    virtual ~ClearableContainer() = default;

    // Copy assignment
    ClearableContainer &operator=(const ClearableContainer &) = delete;
    // Move assignment
    ClearableContainer &operator=(ClearableContainer &&) noexcept = delete;

    // Comparison operators
    bool operator==(const ClearableContainer &) const noexcept = delete;
    bool operator!=(const ClearableContainer &) const noexcept = delete;

    // Specific member functions
    virtual void Clear() = 0;
  };

  class ResizableContainer : virtual public ClearableContainer
  {
  public:
    virtual ~ResizableContainer() = default;

    // Copy assignment
    ResizableContainer &operator=(const ResizableContainer &) noexcept = delete;
    // Move assignment
    ResizableContainer &operator=(ResizableContainer &&) noexcept = delete;

    // Comparison operators
    bool operator==(const ResizableContainer &Ccon) const noexcept = delete;
    bool operator!=(const ResizableContainer &Ccon) const noexcept = delete;

    // Specific member functions
    virtual void Resize(unsigned long) = 0;
    void Clear() override { Resize(0); }
  };

}

#endif
