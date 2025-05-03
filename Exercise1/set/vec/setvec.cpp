namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec() : Vector<Data>::Vector(INIT_SIZE){};

    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con) : Vector<Data>::Vector(con), tail(con.Size()), totalElems(con.Size())
    {
        if (size < INIT_SIZE)
        {
            Resize(INIT_SIZE);
        }
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) : Vector<Data>::Vector(std::move(con)), tail(con.Size()), totalElems(con.Size())
    {
        if (size < INIT_SIZE)
        {
            Resize(INIT_SIZE);
        }
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con) : Vector<Data>::Vector(con), head(con.head), tail(con.tail), totalElems(con.totalElems) {}

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con) : Vector<Data>::Vector(std::move(con))
    {
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        std::swap(totalElems, con.totalElems);
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        Vector<Data>::operator=(con);
        head = con.head;
        tail = con.tail;
        totalElems = con.totalElems;
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con)
    {
        Vector<Data>::operator=(std::move(con));
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        std::swap(totalElems, con.totalElems);
        return *this;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        if (con.totalElems != totalElems)
        {
            return false;
        }
        for (unsigned long index = 0; index < totalElems; index++)
        {
            if (elements[(head + index) % size] != con[(con.head + index) % con.size])
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
        if (totalElems == 0)
        {
            throw std::length_error("Empty Set");
        }
        return elements[tail];
    }

    template <typename Data>
    Data SetVec<Data>::MinNRemove()
    {
        if (totalElems == 0)
        {
            throw std::length_error("Empty Set");
        }
        Data min = elements[tail];
        RemoveMin();
        return min;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        tail = (tail + 1) % size;
        totalElems--;
        if (totalElems < size / REDUCE_FACTOR)
        {
            Resize(size / INCREASE_FACTOR);
        }
    }

    template <typename Data>
    const Data& SetVec<Data>::Max() const
    {
        if (totalElems == 0)
        {
            throw std::length_error("Empty Set");
        }
        return elements[(head - 1 + size) % size];
    }

    template <typename Data>
    Data SetVec<Data>::MaxNRemove()
    {
        if (totalElems == 0)
        {
            throw std::length_error("Empty Set");
        }
        Data max = elements[(head - 1 + size) % size];
        RemoveMax();
        return max;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        head = (head - 1 + size) % size;
        totalElems--;
        if (totalElems < size / REDUCE_FACTOR)
        {
            Resize(size / INCREASE_FACTOR);
        }
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &data) const
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] < data)
            {
                return elements[index];
            }
            index = (index + 1) % size;
        }
        throw std::length_error("Predecessor not found");
    }

    template <typename Data>
    const Data &SetVec<Data>::PredecessorNRemove(const Data &data)
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] < data)
            {
                Data &predecessor = elements[index];
                RemovePredecessor(data);
                return predecessor;
            }
            index = (index + 1) % size;
        }
        throw std::length_error("Predecessor not found");
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
        if (totalElems == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] < data)
            {
                for (unsigned long i = index; i != tail; i = (i - 1 + size) % size)
                {
                    elements[i] = elements[(i - 1 + size) % size];
                }
                tail = (tail + 1) % size;
                totalElems--;
                if (totalElems < size / REDUCE_FACTOR)
                {
                    Resize(size / INCREASE_FACTOR);
                }
                return;
            }
            index = (index + 1) % size;
        }
        throw std::length_error("Predecessor not found");
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &data) const
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] > data)
            {
                return elements[index];
            }
            index = (index + 1) % size;
        }
        throw std::length_error("Successor not found");
    }

    template <typename Data>
    const Data &SetVec<Data>::SuccessorNRemove(const Data &data)
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] > data)
            {
                Data &successor = elements[index];
                RemoveSuccessor(data);
                return successor;
            }
            index = (index + 1) % size;
        }
        throw std::length_error("Successor not found");
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {
        if (totalElems == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] > data)
            {
                for (unsigned long i = index; i != head; i = (i + 1) % size)
                {
                    elements[i] = elements[(i + 1) % size];
                }
                head = (head - 1 + size) % size;
                totalElems--;
                if (totalElems < size / REDUCE_FACTOR)
                {
                    Resize(size / INCREASE_FACTOR);
                }
                return;
            }
            index = (index + 1) % size;
        }
        throw std::length_error("Successor not found");
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        if (Exists(data))
        {
            return false;
        }
        if (totalElems == size)
        {
            Resize(size * INCREASE_FACTOR);
        }
        elements[head] = data;
        head = (head + 1) % size;
        totalElems++;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        if (Exists(data))
        {
            return false;
        }
        if (totalElems == size)
        {
            Resize(size * INCREASE_FACTOR);
        }
        elements[head] = std::move(data);
        head = (head + 1) % size;
        totalElems++;
        return true;
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
        if (size == 0)
        {
            throw std::length_error("Empty Set");
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] == data)
            {
                for (unsigned long i = index; i != tail; i = (i - 1 + size) % size)
                {
                    elements[i] = elements[(i - 1 + size) % size];
                }
                tail = (tail + 1) % size;
                totalElems--;
                if (totalElems < size / REDUCE_FACTOR)
                {
                    Resize(size / INCREASE_FACTOR);
                }
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](unsigned long index) const
    {
        if (index >= totalElems)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[(tail + 1 + index) % size];
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        if (totalElems == 0)
        {
            return false;
        }
        unsigned long index = (tail + 1) % size;
        while (index != head)
        {
            if (elements[index] == data)
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
        Resize(INIT_SIZE);
        head = 0;
        tail = 0;
        totalElems = 0;
    }

    template <typename Data>
    void SetVec<Data>::Resize(const unsigned long dim)
    {
        if (dim < INIT_SIZE)
        {
            throw std::length_error("Size too small");
        }
        if (dim != size)
        {
            Data *newElements = new Data[dim];
            for (unsigned long i = 0; i < totalElems; i++)
            {
                newElements[i] = elements[(tail + 1 + i) % size];
            }
            delete[] elements;
            elements = newElements;
            size = dim;
            head = totalElems;
            tail = 0;
        }
    }
}
