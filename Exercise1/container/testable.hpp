#ifndef TESTABLE_HPP
#define TESTABLE_HPP
#include "container.hpp"


namespace lasd
{

  template <typename Data>
  class TestableContainer : public virtual Container
  {

  public:

    virtual ~TestableContainer() = default;

    TestableContainer &operator=(const TestableContainer &) = delete;
    TestableContainer &operator=(TestableContainer &&) noexcept = delete;

    bool operator==(const TestableContainer &) const noexcept = delete;
    bool operator!=(const TestableContainer &) const noexcept = delete;

    virtual bool Exists(const Data &data) const noexcept = 0;
  };

}

#endif
