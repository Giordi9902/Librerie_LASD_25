namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con)
    {
        con.Traverse([this](const Data &dat)
                     { Insert(dat); });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con)
    {
        con.Map([this](Data &dat)
                { Insert(std::move(dat)); });
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con) : vector(con.vector) {}

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con) noexcept : vector(std::move(con.vector)) {}

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        vector = con.vector;
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con) noexcept
    {
        vector = std::move(con.vector);
        return *this;
    }

    template <typename Data>
    bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        return vector == con.vector;
    }

    template <typename Data>
    bool SetVec<Data>::operator!=(const SetVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetVec<Data>::Min() const
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        return vector[head];
    }

    template <typename Data>
    const Data SetVec<Data>::MinNRemove()
    {
        const Data minValue = Min();
        RemoveMin();
        return minValue;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        head = (head + 1) % size;
        --totalElements;
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        return vector[(tail - 1 + size) % size];
    }

    template <typename Data>
    const Data SetVec<Data>::MaxNRemove()
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }

        const Data maxValue = Max();
        tail = (tail - 1 + size) % size;
        --totalElements;
        return maxValue;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        tail = (tail - 1 + size) % size;
        --totalElements;
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &dat) const
    {
        ulong index = FindIndex(dat);
        if (index == 0)
        {
            throw std::out_of_range("No predecessor exists.");
        }
        return vector[(head + index - 1) % size];
    }

    template <typename Data>
    const Data SetVec<Data>::PredecessorNRemove(const Data &dat)
    {
        const Data pred = Predecessor(dat);
        Remove(pred);
        return pred;
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &dat)
    {
        ulong index = FindIndex(dat);
        if (index == 0)
        {
            throw std::out_of_range("No predecessor exists.");
        }
        Remove(vector[index - 1]);
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &dat) const
    {
        ulong index = FindIndex(dat);
        if (index == totalElements - 1)
        {
            throw std::out_of_range("No successor exists.");
        }
        return vector[(head + index + 1) % size];
    }

    template <typename Data>
    const Data SetVec<Data>::SuccessorNRemove(const Data &dat)
    {
        const Data succ = Successor(dat);
        Remove(succ);
        return succ;
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &dat)
    {
        ulong index = FindIndex(dat);
        if (index == vector.Size() - 1)
        {
            throw std::out_of_range("No successor exists.");
        }
        Remove(vector[index + 1]);
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &dat)
    {
        if (Exists(dat))
        {
            return false;
        }

        if (totalElements == size)
        {
            Resize(size * 2); // Ensure there's space
        }

        ulong index = FindInsertIndex(dat); // Logical index where to insert
        ulong physicalIndex = (head + index) % size;

        // Shift elements to the right to make room
        for (ulong i = totalElements; i > index; --i)
        {
            ulong from = (head + i - 1) % size;
            ulong to = (head + i) % size;
            vector[to] = vector[from];
        }

        // Insert the new element
        vector[physicalIndex] = dat;

        ++totalElements;
        tail = (head + totalElements) % size;

        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&dat)
    {
        if (Exists(dat))
        {
            return false;
        }

        if (totalElements == size)
        {
            Resize(size * 2);
        }

        ulong index = FindInsertIndex(dat);
        ulong physicalIndex = (head + index) % size;

        // Shift elements right to make space
        for (ulong i = totalElements; i > index; --i)
        {
            ulong from = (head + i - 1) % size;
            ulong to = (head + i) % size;
            vector[to] = std::move(vector[from]);
        }

        // Move-insert the new element
        vector[physicalIndex] = std::move(dat);

        ++totalElements;
        tail = (head + totalElements) % size;

        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &dat)
    {
        ulong index = FindIndex(dat);
        if (index == size)
        {
            return false;
        }
        for (ulong i = index; i < totalElements - 1; ++i)
        {
            vector[(head + i) % size] = std::move(vector[(head + i + 1) % size]);
        }
        tail = (tail - 1 + size) % size;
        --totalElements;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &dat) const noexcept
    {
        return FindIndex(dat) != size;
    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        totalElements = 0;
        vector.Clear();
        vector.Resize(INIT_SIZE);
        size = INIT_SIZE;
    }

    template <typename Data>
    ulong SetVec<Data>::FindIndex(const Data &dat) const
    {
        for (ulong i = 0; i < totalElements; ++i)
        {
            if (vector[(head + i) % size] == dat)
            {
                return i;
            }
        }
        return totalElements;
    }

    template <typename Data>
    ulong SetVec<Data>::FindInsertIndex(const Data &dat) const
    {
        ulong low = 0, high = totalElements;
        while (low < high)
        {
            ulong mid = (low + high) / 2;
            if (vector[(head + mid) % size] < dat)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= totalElements)
            throw std::out_of_range("Index out of range.");
        return vector[(head + index) % size];
    }

    template <typename Data>
    void SetVec<Data>::Resize(ulong newSize)
    {
        if (newSize == 0)
        {
            newSize = 1;
        }

        Vector<Data> newVector(newSize);
        for (ulong i = 0; i < totalElements; ++i)
        {
            newVector[i] = std::move(vector[(head + i) % size]);
        }

        vector = std::move(newVector);
        head = 0;
        tail = totalElements;
        size = newSize;
    }

}