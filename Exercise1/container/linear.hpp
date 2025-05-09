#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "mappable.hpp"

namespace lasd
{

    template <typename Data>
    class LinearContainer : virtual public PreOrderTraversableContainer<Data>,
                            virtual public PostOrderTraversableContainer<Data>
    {
    protected:
        using Container::size;

    public:
        virtual ~LinearContainer() = default;

        LinearContainer &operator=(const LinearContainer &) = delete;
        LinearContainer &operator=(LinearContainer &&) noexcept = delete;

        inline bool operator==(const LinearContainer &) const noexcept;
        inline bool operator!=(const LinearContainer &) const noexcept;

        virtual const Data &operator[](const ulong) const = 0;
        virtual inline const Data &Front() const;
        virtual inline const Data &Back() const;

        using typename TraversableContainer<Data>::TraverseFun;
        inline void Traverse(const TraverseFun) const override;
        inline void PreOrderTraverse(const TraverseFun) const override;
        inline void PostOrderTraverse(const TraverseFun) const override;
    };

    template <typename Data>
    class MutableLinearContainer : virtual public LinearContainer<Data>,
                                   virtual public PreOrderMappableContainer<Data>,
                                   virtual public PostOrderMappableContainer<Data>
    {
    protected:
        using Container::size;

    public:
        virtual ~MutableLinearContainer() = default;

        MutableLinearContainer &operator=(const MutableLinearContainer &) = delete;
        MutableLinearContainer &operator=(MutableLinearContainer &&) noexcept = delete;

        virtual Data &operator[](const ulong) = 0;

        virtual inline Data &Front();
        virtual inline Data &Back();

        using LinearContainer<Data>::operator[];
        using LinearContainer<Data>::Front;
        using LinearContainer<Data>::Back;

        using typename MappableContainer<Data>::MapFun;
        inline void Map(const MapFun) override;
        inline void PreOrderMap(const MapFun) override;
        inline void PostOrderMap(const MapFun) override;
    };

    template <typename Data>
    class SortableLinearContainer : virtual public MutableLinearContainer<Data>
    {
    protected:
        using Container::size;

    public:
        virtual ~SortableLinearContainer() = default;

        SortableLinearContainer &operator=(const SortableLinearContainer &) const = delete;
        SortableLinearContainer &operator=(SortableLinearContainer &&) noexcept = delete;

        inline void Sort() noexcept;

    protected:
        void QuickSort(ulong, ulong) noexcept;
        ulong Partition(ulong, ulong) noexcept;
    };

}

#include "linear.cpp"

#endif
