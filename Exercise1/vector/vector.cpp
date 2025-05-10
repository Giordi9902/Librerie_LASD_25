
namespace lasd
{
    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> &con) : Vector(con.Size())
    {
        ulong i = 0;
        con.Traverse(
            [this, &i](const Data &currData)
            {
                elements[i++] = currData;
            });
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data> &&con) : Vector(con.Size())
    {
        ulong i = 0;
        con.Map(
            [this, &i](Data &currData)
            {
                std::swap(elements[i++], currData);
            });
    }

    template <typename Data>
    Vector<Data>::Vector(const Vector<Data> &vec) : Vector(vec.size)
    {
        std::uninitialized_copy(vec.elements, vec.elements + size, elements);
    }

    template <typename Data>
    Vector<Data>::Vector(Vector<Data> &&vec) noexcept
    {
        std::swap(size, vec.size);
        std::swap(elements, vec.elements);
    }

    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vec)
    {
        Vector<Data> *temp = new Vector<Data>(vec);
        std::swap(*temp, *this);
        delete temp;
        return *this;
    }

    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(Vector<Data> &&vec) noexcept
    {
        std::swap(size, vec.size);
        std::swap(elements, vec.elements);
        return *this;
    }

    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data> &vec) const noexcept
    {
        if (size != vec.size)
        {
            return false;
        }

        for (ulong i = 0; i < size; i++)
        {
            if (elements[i] != vec[i])
            {
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data> &vec) const noexcept
    {
        return !(*this == vec);
    }

    template <typename Data>
    const Data &Vector<Data>::operator[](ulong i) const
    {
        if (i >= size)
        {
            throw std::out_of_range("This Vector has not that many elements");
        }
        return elements[i];
    }

    template <typename Data>
    Data &Vector<Data>::operator[](ulong i)
    {
        return const_cast<Data&>(static_cast<const Vector<Data>*>(this)->operator[](i));
    }

    template <typename Data>
    const Data &Vector<Data>::Front() const
    {
        if (size != 0)
            return elements[0];
        throw std::length_error("The Vector is empty");
    }

    template <typename Data>
    Data &Vector<Data>::Front()
    {
        return const_cast<Data&>(static_cast<const Vector<Data>*>(this)->Front());
    }

    template <typename Data>
    const Data &Vector<Data>::Back() const
    {
        if (size != 0)
            return elements[size - 1];
        throw std::length_error("The Vector is empty");
    }

    template <typename Data>
    Data &Vector<Data>::Back()
    {
        return const_cast<Data&>(static_cast<const Vector<Data>*>(this)->Back());
    }

    template <typename Data>
    void Vector<Data>::Clear()
    {
        delete[] elements;
        size = 0;
        elements = nullptr;
    }

    template <typename Data>
    void Vector<Data>::Resize(ulong newSize)
    {
        if (newSize == size)
        {
            return;
        }

        if (newSize == 0)
        {
            Clear();
            return;
        }

        Data *temp = new Data[newSize]{};

        ulong min = std::min(newSize, size);

        for (ulong i = 0; i < min; ++i)
            std::swap(elements[i], temp[i]);

        std::swap(elements, temp);
        delete[] temp;

        size = newSize;
    }

    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data> &con)
    {
        Vector<Data>::operator=(con);
        return *this;
    }

    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data> &&con) noexcept
    {
        Vector<Data>::operator=(std::move(con));
        return *this;
    }
}
