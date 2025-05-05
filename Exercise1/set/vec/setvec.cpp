namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec() : vector(INIT_SIZE), head(0), tail(0), totalElems(0) {}

    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con) : vector(con), tail(con.Size()), totalElems(con.Size())
    {
        if (size < INIT_SIZE)
        {
            Resize(INIT_SIZE);
        }
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) noexcept : vector(std::move(con)), tail(con.Size()), totalElems(con.Size())
    {
        if (size < INIT_SIZE)
        {
            Resize(INIT_SIZE);
        }
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con) : vector(con), head(con.head), tail(con.tail), totalElems(con.totalElems) {}

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con) : vector(std::move(con))
    {
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        std::swap(totalElems, con.totalElems);
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        if (this != &con)
        {
            Clear();
            vector = con.vector;
            head = con.head;
            tail = con.tail;
            totalElems = con.totalElems;
        }
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con)
    {
        if (this != &con)
        {
            vector = std::move(con.vector);
            std::swap(tail, con.tail);
            std::swap(head, con.head);
            std::swap(totalElems, con.totalElems);
        }
        return *this;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        if (totalElems != con.totalElems)
        {
            return false;
        }

        ulong index1 = head;
        ulong index2 = con.head;

        for (ulong i = 0; i < totalElems; ++i)
        {
            if (vector[index1] != con.vector[index2])
            {
                return false;
            }
            index1 = (index1 + 1) % vector.Size();
            index2 = (index2 + 1) % con.vector.Size();
        }

        return true;
    }

    template <typename Data>
    ulong SetVec<Data>::PredecessorIndex(const Data &dat) const
    {
        if (totalElems == 0)
        {
            throw std::length_error("Set is empty");
        }

        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == dat)
            {
                return (index - 1 + vector.Size()) % vector.Size();
            }
            index = (index + 1) % vector.Size();
        }
        return tail;
    }

    template <typename Data>
    ulong SetVec<Data>::SuccessorIndex(const Data &dat) const
    {
        if (totalElems == 0)
        {
            throw std::length_error("Set is empty");
        }

        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == dat)
            {
                return (index + 1) % vector.Size();
            }
            index = (index + 1) % vector.Size();
        }
        return head;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator!=(const SetVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetVec<Data>::Min() const
    {
        return vector[head];
    }

    template <typename Data>
    const Data &SetVec<Data>::MinNRemove()
    {
        const Data& removedMin = Min();
        RemoveMin();
        return removedMin;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if (totalElems == 0)
        {
            throw std::length_error("Set is empty");
        }
        head = (head + 1) % vector.Size();
        totalElems--;
        if (totalElems == 0)
        {
            tail = head;
        }
        if (totalElems < vector.Size() / REDUCE_FACTOR && vector.Size() > INIT_SIZE)
        {
            Resize(vector.Size() / REDUCE_FACTOR);
        }
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
        return vector[tail];
    }

    template <typename Data>
    const Data &SetVec<Data>::MaxNRemove()
    {
        const Data& removedMax = Max();
        RemoveMax();
        return removedMax;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        Remove(Max());
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &data) const
    {
        if (totalElems == 0)
        {
            throw std::length_error("Set is empty");
        }

        ulong index = PredecessorIndex(data);
        if (index == tail)
        {
            throw std::length_error("No predecessor found");
        }
        return vector[index];
    }

    template <typename Data>
    const Data &SetVec<Data>::PredecessorNRemove(const Data &data)
    {
        const Data& removedPredecessor = Predecessor(data);
        RemovePredecessor(data);
        return removedPredecessor;

    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
        Remove(Predecessor(data));
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &data) const
    {
        if (totalElems == 0)
        {
            throw std::length_error("Set is empty");
        }

        ulong index = SuccessorIndex(data);
        if (index == head)
        {
            throw std::length_error("No successor found");
        }
        return vector[index];
    }

    template <typename Data>
    const Data &SetVec<Data>::SuccessorNRemove(const Data &data)
    {
        const Data& removedSuccessor = Successor(data);
        RemoveSuccessor(data);
        return removedSuccessor;
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {
        Remove(Successor(data));
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
        if (Exists(data))
        {
            return false;
        }
        if (totalElems == vector.Size())
        {
            Resize(vector.Size() * INCREASE_FACTOR);
        }
        if (totalElems == 0)
        {
            vector[tail] = data;
        }
        else
        {
            tail = (tail + 1) % vector.Size();
            vector[tail] = data;
        }
        totalElems++;
        return true;

    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
        if (Exists(data))
        {
            return false;
        }
        if (totalElems == vector.Size())
        {
            Resize(vector.Size() * INCREASE_FACTOR);
        }
        if (totalElems == 0)
        {
            vector[tail] = std::move(data);
        }
        else
        {
            tail = (tail + 1) % vector.Size();
            vector[tail] = std::move(data);
        }
        totalElems++;
        return true;

    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
        if (totalElems == 0)
        {
            throw std::length_error("Set is empty");
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                for (ulong i = index; i != tail; i = (i + 1) % vector.Size())
                {
                    vector[i] = vector[(i + 1) % vector.Size()];
                }
                tail = (tail - 1 + vector.Size()) % vector.Size();
                totalElems--;
                return true;
            }
            index = (index + 1) % vector.Size();
        }
        return false;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= totalElems)
        {
            throw std::out_of_range("Index out of range");
        }
        return vector[(head + index) % vector.Size()];
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        if (totalElems == 0)
        {
            return false;
        }
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                return true;
            }
            index = (index + 1) % vector.Size();
        }
        return false;
    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        vector.Resize(INIT_SIZE);
        head = 0;
        tail = 0;
        totalElems = 0;
    }

    template <typename Data>
    void SetVec<Data>::Resize(const ulong dim)
    {
        Vector<Data> newVector(dim);
        for (ulong i = 0; i < totalElems; ++i)
        {
            newVector[i] = std::move(vector[(head + i) % vector.Size()]);
        }
        vector = std::move(newVector);
        head = 0;
        tail = totalElems;
    }
}
