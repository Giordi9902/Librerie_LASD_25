
namespace lasd
{
    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data> &con) const noexcept
    {
        if (this->Size() != con.Size())
        {
            return false;
        }

        for (ulong i = 0; i < this->Size(); ++i)
        {
            if ((*this)[i] != con[i])
            {
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &LinearContainer<Data>::Front() const
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[0];
    }

    template <typename Data>
    const Data &LinearContainer<Data>::Back() const
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[size - 1];
    }

    template <typename Data>
    void LinearContainer<Data>::Traverse(const TraverseFun func) const
    {
        PreOrderTraverse(func);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(const TraverseFun func) const
    {
        for (ulong i = 0; i < size; ++i)
        {
            func((*this)[i]);
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(const TraverseFun func) const
    {

        for (ulong i = size; i > 0;)
        {
            func((*this)[--i]);
        }
    }

    template <typename Data>
    Data &MutableLinearContainer<Data>::Front()
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[0];
    }

    template <typename Data>
    Data &MutableLinearContainer<Data>::Back()
    {
        if (size == 0)
        {
            throw std::length_error("Empty structure.");
        }
        return (*this)[size - 1];
    }

    template <typename Data>
    void MutableLinearContainer<Data>::Map(const MapFun func)
    {
        PreOrderMap(func);
    }

    template <typename Data>
    void MutableLinearContainer<Data>::PreOrderMap(const MapFun func)
    {
        for (ulong index = 0; index < size; ++index)
        {
            func((*this)[index]);
        }
    }

    template <typename Data>
    void MutableLinearContainer<Data>::PostOrderMap(const MapFun func)
    {
        for (ulong index = size; index > 0;)
        {
            func((*this)[--index]);
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept
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
