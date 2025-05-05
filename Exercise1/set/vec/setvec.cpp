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
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) : vector(std::move(con)), tail(con.Size()), totalElems(con.Size()) noexcept
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
    inline bool SetVec<Data>::operator!=(const SetVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetVec<Data>::Min() const
    {
    }

    template <typename Data>
    const Data &SetVec<Data>::MinNRemove()
    {
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
    }

    template <typename Data>
    const Data &SetVec<Data>::MaxNRemove()
    {
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        Remove(Max());
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &data) const
    {
    }

    template <typename Data>
    const Data &SetVec<Data>::PredecessorNRemove(const Data &data)
    {
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
        Remove(Predecessor(data));
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &data) const
    {
    }

    template <typename Data>
    const Data &SetVec<Data>::SuccessorNRemove(const Data &data)
    {
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {
        Remove(Successor(data));
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
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
