
namespace lasd
{
    template <typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer<Data> &con) const noexcept
    {
        if (size != con.size)
        {
            return false;
        }

        for (ulong i = 0; i < size; ++i)
        {
            if ((*this)[i] != con[i])
            {
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[0];
    }

    template <typename Data>
    inline const Data &LinearContainer<Data>::Back() const
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[size - 1];
    }

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun func) const
    {
        PreOrderTraverse(func);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(const TraverseFun func) const
    {
        for (ulong i = 0; i < size; ++i)
        {
            func((*this)[i]);
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(const TraverseFun func) const
    {

        for (ulong i = size; i > 0;)
        {
            func((*this)[--i]);
        }
    }

    template <typename Data>
    inline Data &MutableLinearContainer<Data>::Front()
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[0];
    }

    template <typename Data>
    inline Data &MutableLinearContainer<Data>::Back()
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[size - 1];
    }

    template <typename Data>
    inline void MutableLinearContainer<Data>::Map(MapFun func)
    {
        PreOrderMap(func);
    }

    template <typename Data>
    inline void MutableLinearContainer<Data>::PreOrderMap(MapFun func)
    {
        for (ulong index = 0; index < size; ++index)
        {
            func((*this)[index]);
        }
    }

    template <typename Data>
    inline void MutableLinearContainer<Data>::PostOrderMap(MapFun func)
    {
        for (ulong index = size; index > 0;)
        {
            func((*this)[--index]);
        }
    }

    template <typename Data>
    inline void SortableLinearContainer<Data>::Sort() noexcept
    {
        QuickSort(0, size - 1);
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept
    {
        if (p < r)
        {
            ulong q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q + 1, r);
        }
    }

    template <typename Data>
    ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r) noexcept
    {
        Data x = this->operator[](p);
        ulong i = p - 1;
        ulong j = r + 1;
        do
        {
            do
            {
                j--;
            } while (x < this->operator[](j));
            do
            {
                i++;
            } while (x > this->operator[](i));
            if (i < j)
            {
                std::swap(this->operator[](i), this->operator[](j));
            }
        } while (i < j);
        return j;
    }
}
