
#ifndef SET_HPP
#define SET_HPP

#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"

namespace lasd
{
  template <typename Data>
  class Set : public virtual OrderedDictionaryContainer<Data>,
              public virtual LinearContainer<Data>,
              public virtual ClearableContainer
  {

  public:
    virtual ~Set() = default;
    Set &operator=(const Set &) = delete;
    Set &operator=(Set &&) noexcept = delete;
  };

}

#endif
