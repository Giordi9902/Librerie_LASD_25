namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec() : vector(INIT_SIZE), head(0), tail(0)
    {
        size = INIT_SIZE;
    }

    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con) : vector(con.Size())
    {
        size = con.Size();
        con.Traverse(
            [this](const Data &dat)
            {
                if (!Exists(dat))
                {
                    Insert(dat);
                }
            });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) noexcept : vector(con.Size())
    {
        size = con.Size();
        con.Map(
            [this](Data &dat)
            {
                if (!Exists(dat))
                {
                    Insert(std::move(dat));
                }
            });
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con)
    {
        size = con.size;
        head = con.head;
        tail = con.tail;
        vector = con.vector;
    }

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con)
    {
        std::swap(size, con.size);
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        std::swap(vector, con.vector);
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        if (this != &con)
        {
            size = con.size;
            head = con.head;
            tail = con.tail;
            vector = con.vector;
        }
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con)
    {
        if (this != &con)
        {
            std::swap(size, con.size);
            std::swap(head, con.head);
            std::swap(tail, con.tail);
            std::swap(vector, con.vector);
        }
        return *this;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        if (Size() != con.Size())
        {
            return false;
        }
        for (ulong i = 0; i < Size(); ++i)
        {
            if (!con.Exists(vector[(head + i) % size]))
            {
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator!=(const SetVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetVec<Data>::Min() const
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        return vector[head];
    }

    template <typename Data>
    const Data &SetVec<Data>::MinNRemove()
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        const Data &minValue = vector[head];
        head = (head + 1) % size;
        return minValue;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        head = (head + 1) % size;
        if (Size() < size / 4 && size > INIT_SIZE) // Riduci la dimensione se necessario
        {
            Resize(size / 2);
        }
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        return vector[(tail - 1) % size];
    }

    template <typename Data>
    const Data &SetVec<Data>::MaxNRemove()
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        const Data &maxValue = vector[(tail - 1) % size];
        tail = (tail - 1) % size;
        return maxValue;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        tail = (tail - 1) % size;
        if (Size() < size / 4 && size > INIT_SIZE)
        {
            Resize(size / 2);
        }
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &data) const
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                return vector[(index - 1) % size];
            }
            index = (index + 1) % size;
        }
        throw std::out_of_range("Element not found.");
    }

    template <typename Data>
    const Data &SetVec<Data>::PredecessorNRemove(const Data &data)
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                const Data &predValue = vector[(index - 1) % size];
                Remove(predValue);
                return predValue;
            }
            index = (index + 1) % size;
        }
        throw std::out_of_range("Element not found.");
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                Remove(vector[(index - 1) % size]);
                return;
            }
            index = (index + 1) % size;
        }
        throw std::out_of_range("Element not found.");
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &data) const
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                return vector[(index + 1) % size];
            }
            index = (index + 1) % size;
        }
        throw std::out_of_range("Element not found.");
    }

    template <typename Data>
    const Data &SetVec<Data>::SuccessorNRemove(const Data &data)
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                const Data &succValue = vector[(index + 1) % size];
                Remove(succValue);
                return succValue;
            }
            index = (index + 1) % size;
        }
        throw std::out_of_range("Element not found.");
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {
        if (Empty())
        {
            throw std::length_error("SetVec is empty.");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                Remove(vector[(index + 1) % size]);
                return;
            }
            index = (index + 1) % size;
        }
        throw std::out_of_range("Element not found.");
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
        if (Exists(data))
        {
            return false;
        }
        if (Size() == size - 1) // Controllo se il vettore è pieno
        {
            Resize(size * 2); // Raddoppia la dimensione del vettore
        }
        vector[tail] = data;
        tail = (tail + 1) % size;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
        if (Exists(data))
        {
            return false;
        }
        if (Size() == size - 1) // Controllo se il vettore è pieno
        {
            Resize(size * 2); // Raddoppia la dimensione del vettore
        }
        vector[tail] = std::move(data);
        tail = (tail + 1) % size;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
        if (Empty())
        {
            return false;
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                for (ulong i = index; i != (tail - 1) % size; i = (i + 1) % size)
                {
                    vector[i] = vector[(i + 1) % size];
                }
                tail = (tail - 1) % size;
                if (Size() < size / 4 && size > INIT_SIZE) // Riduci la dimensione se necessario
                {
                    Resize(size / 2);
                }
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= Size())
        {
            throw std::out_of_range("Index out of range.");
        }
        return vector[(head + index) % size];
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        vector.Clear();
        size = INIT_SIZE;
    }

    template <typename Data>
    void SetVec<Data>::Resize(ulong newDim)
    {
        if (newDim < Size())
        {
            throw std::length_error("New size is smaller than current size.");
        }
        Vector<Data> newVector(newDim);
        ulong index = head;
        ulong newIndex = 0;
        while (index != tail)
        {
            newVector[newIndex] = vector[index];
            index = (index + 1) % size;
            newIndex++;
        }
        vector = std::move(newVector);
        head = 0;
        tail = newIndex;
    }

    template <typename Data>
    bool SetVec<Data>::Empty() const noexcept
    {
        return (head == tail);
    }

    template <typename Data>
    inline ulong SetVec<Data>::Size() const noexcept
    {
        return (((size + tail) - head) % size);
    }
}
