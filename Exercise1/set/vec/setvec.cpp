namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con) : vector(INIT_SIZE), head(0), tail(0), totalElements(0)
    {
        con.Traverse([this](const Data &dat)
                     {
            if(!Exists(dat)){
                Insert(dat);
            } });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) noexcept : vector(INIT_SIZE), head(0), tail(0), totalElements(0)
    {
        con.Map([this](Data &dat)
                {
            if(!Exists(dat)){
                Insert(std::move(dat));
            } });
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con) : vector(con.vector), head(con.head), tail(con.tail), totalElements(con.totalElements) {}

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con) : vector(std::move(con.vector)), head(con.head), tail(con.tail), totalElements(con.totalElements)
    {
        con.head = 0;
        con.tail = 0;
        con.totalElements = 0;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        vector = con.vector;
        head = con.head;
        tail = con.tail;
        totalElements = con.totalElements;
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con)
    {
        std::swap(vector, con.vector);
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        std::swap(totalElements, con.totalElements);
        return *this;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        if (totalElements != con.totalElements)
        {
            return false;
        }
        for (ulong i = 0; i < totalElements; ++i)
        {
            if (vector[(head + i) % vector.Size()] != con.vector[(con.head + i) % con.vector.Size()])
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
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        return vector[head];
    }

    template <typename Data>
    const Data &SetVec<Data>::MinNRemove()
    {
        const Data &minValue = Min();
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
        head = (head + 1) % vector.Size();
        --totalElements;
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        return vector[(tail - 1 + vector.Size()) % vector.Size()];
    }

    template <typename Data>
    const Data &SetVec<Data>::MaxNRemove()
    {
        const Data &maxValue = Max();
        RemoveMax();
        return maxValue;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if (totalElements == 0)
        {
            throw std::length_error("SetVec is empty.");
        }
        tail = (tail - 1 + vector.Size()) % vector.Size();
        --totalElements;
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &data) const
    {
        ulong index = Find(data);
        if (index == head)
        {
            throw std::out_of_range("No predecessor exists.");
        }
        return vector[(index - 1 + vector.Size()) % vector.Size()];
    }

    template <typename Data>
    const Data &SetVec<Data>::PredecessorNRemove(const Data &data)
    {
        const Data &pred = Predecessor(data);
        Remove(pred);
        return pred;
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
        const Data &pred = Predecessor(data);
        Remove(pred);
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &data) const
    {
        ulong index = Find(data);
        if (index == (tail - 1 + vector.Size()) % vector.Size())
        {
            throw std::out_of_range("No successor exists.");
        }
        return vector[(index + 1) % vector.Size()];
    }

    template <typename Data>
    const Data &SetVec<Data>::SuccessorNRemove(const Data &data)
    {
        const Data &succ = Successor(data);
        Remove(succ);
        return succ;
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {
        const Data &succ = Successor(data);
        Remove(succ);
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
        if (Exists(data))
        {
            return false;
        }
        if (totalElements == vector.Size())
        {
            Resize(vector.Size() * 2);
        }
        ulong index = LowerBound(data);
        for (ulong i = totalElements; i > index; --i)
        {
            vector[(head + i) % vector.Size()] = vector[(head + i - 1) % vector.Size()];
        }
        vector[(head + index) % vector.Size()] = data;
        tail = (tail + 1) % vector.Size();
        ++totalElements;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
        if (Exists(data))
        {
            return false;
        }
        if (totalElements == vector.Size())
        {
            Resize(vector.Size() * 2);
        }
        ulong index = LowerBound(data);
        for (ulong i = totalElements; i > index; --i)
        {
            vector[(head + i) % vector.Size()] = std::move(vector[(head + i - 1) % vector.Size()]);
        }
        vector[(head + index) % vector.Size()] = std::move(data);
        tail = (tail + 1) % vector.Size();
        ++totalElements;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
        ulong index = Find(data);
        if (index == vector.Size())
        {
            return false;
        }
        for (ulong i = index; i < totalElements - 1; ++i)
        {
            vector[(head + i) % vector.Size()] = vector[(head + i + 1) % vector.Size()];
        }
        tail = (tail - 1 + vector.Size()) % vector.Size();
        --totalElements;
        return true;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= totalElements)
        {
            throw std::out_of_range("Index out of range.");
        }
        return vector[(head + index) % vector.Size()];
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        return Find(data) != vector.Size();
    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        totalElements = 0;
    }

    template <typename Data>
    ulong SetVec<Data>::Size() const noexcept
    {
        return totalElements;
    }

    template <typename Data>
    bool SetVec<Data>::Empty() const noexcept
    {
        return totalElements == 0;
    }

    template <typename Data>
    ulong SetVec<Data>::Find(const Data &data) const noexcept
    {
        for (ulong i = 0; i < totalElements; ++i)
        {
            if (vector[(head + i) % vector.Size()] == data)
            {
                return (head + i) % vector.Size();
            }
        }
        return vector.Size();
    }

    template <typename Data>
    ulong SetVec<Data>::LowerBound(const Data &data) const noexcept
    {
        for (ulong i = 0; i < totalElements; ++i)
        {
            if (vector[(head + i) % vector.Size()] >= data)
            {
                return i;
            }
        }
        return totalElements;
    }

    template <typename Data>
    void SetVec<Data>::Resize(ulong newDim)
    {
        Vector<Data> newVector(newDim);
        for (ulong i = 0; i < totalElements; ++i)
        {
            newVector[i] = std::move(vector[(head + i) % vector.Size()]);
        }
        vector = std::move(newVector);
        head = 0;
        tail = totalElements;
    }
}