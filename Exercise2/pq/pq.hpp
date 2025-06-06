
#ifndef PQ_HPP
#define PQ_HPP

#include "../container/linear.hpp"

namespace lasd
{

    template <typename Data>
    class PQ : public virtual LinearContainer<Data>, virtual public ClearableContainer
    {

    public:
        virtual ~PQ() = default;

        PQ &operator=(const PQ<Data> &) = delete;
        PQ &operator=(PQ<Data> &&) noexcept = delete;

        virtual const Data &Tip() const = 0;

        virtual void RemoveTip() = 0;

        virtual Data TipNRemove() = 0;

        virtual void Insert(const Data &) = 0;
        virtual void Insert(Data &&) = 0;

        virtual void Change(ulong, const Data &) = 0;
        virtual void Change(ulong, Data &&) = 0;
    };

}

#endif
