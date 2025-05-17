namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec() : vector(INIT_SIZE), head(0), tail(0)
    {
        size = INIT_SIZE;
    }

    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con) : vector(con.Size() * 2), tail(0)
    {
        size = vector.Size();
        con.Traverse([this](const Data &dat)
                     {
            if (!Exists(dat))
            {
                Insert(dat);
            } });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) : vector(con.Size() * 2), tail(0)
    {
        size = vector.Size();
        con.Map([this](const Data &dat)
                {
                    if (!Exists(dat))
                    {
                        Insert(std::move(dat));
                    } });
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con) : vector(con.vector), head(con.head), tail(con.tail)
    {
        size = vector.Size();
    }

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con) noexcept : vector(std::move(con.vector)), head(con.head), tail(con.tail)
    {
        size = vector.Size();
        con.head = 0;
        con.tail = 0;
        con.size = INIT_SIZE;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        if (this != &con)
        {
            vector = con.vector;
            head = con.head;
            tail = con.tail;
            size = con.size;
        }
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con) noexcept
    {
        if (this != &con)
        {
            vector = std::move(con.vector);
            std::swap(head, con.head);
            std::swap(tail, con.tail);
            std::swap(size, con.size);
        }
        return *this;
    }

    template <typename Data>
    bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        if (Size() != con.Size())
        {
            return false;
        }
        ulong index1 = tail;
        ulong index2 = con.tail;
        for (ulong i = 0; i < Size(); ++i)
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
    bool SetVec<Data>::operator!=(const SetVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetVec<Data>::Min() const
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        return vector[tail];
    }

    template <typename Data>
    const Data SetVec<Data>::MinNRemove()
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        Data min = vector[tail];
        tail = (tail + 1) % size;
        CheckNHalve();
        return min;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        tail = (tail + 1) % size;
        CheckNHalve();
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        return vector[(head - 1 + size) % size];
    }

    template <typename Data>
    const Data SetVec<Data>::MaxNRemove()
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        Data max = vector[(head - 1 + size) % size];
        head = (head - 1 + size) % size;
        CheckNHalve();
        return max;
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        if (Size() == 0)
        {
            throw std::length_error("Set is empty");
        }
        head = (head - 1 + size) % size;
        CheckNHalve();
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &dat) const
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        bool found = false;
        ulong predecessorIndex = 0;
        for (ulong i = tail; i != head; i = (i + 1) % size)
        {
            if (vector[i] < dat)
            {
                if (!found || vector[i] > vector[predecessorIndex])
                {
                    predecessorIndex = i;
                    found = true;
                }
            }
        }
        if (!found)
        {
            throw std::length_error("No predecessor found");
        }
        return vector[predecessorIndex];
    }

    template <typename Data>
    const Data SetVec<Data>::PredecessorNRemove(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        Data pred = Predecessor(dat);
        Remove(pred);
        return pred;
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        ulong pos = FindElementIndex(dat);
        if (pos == tail)
        {
            throw std::length_error("No predecessor found");
        }
        Remove(vector[(pos - 1 + size) % size]);
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &dat) const
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        bool found = false;
        ulong successorIndex = 0;
        for (ulong i = tail; i != head; i = (i + 1) % size)
        {
            if (vector[i] > dat)
            {
                if (!found || vector[i] < vector[successorIndex])
                {
                    successorIndex = i;
                    found = true;
                }
            }
        }
        if (!found)
        {
            throw std::length_error("No successor found");
        }
        return vector[successorIndex];
    }

    template <typename Data>
    const Data SetVec<Data>::SuccessorNRemove(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        Data succ = Successor(dat);
        Remove(succ);
        return succ;
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        ulong pos = FindElementIndex(dat);
        if (pos == head - 1)
        {
            throw std::length_error("No successor found");
        }
        Remove(vector[(pos + 1) % size]);
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &dat)
    {
        if (Exists(dat))
            return false;
        else
        {
            InsertAtIndex(dat);
            CheckNDouble();
            return true;
        }
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&dat)
    {
        if (Exists(dat))
            return false;
        else
        {
            InsertAtIndex(std::move(dat));
            CheckNDouble();
            return true;
        }
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &dat)
    {

        long posLong = BinarySearch(dat);
        if (posLong != -1)
        {
            ulong pos = static_cast<ulong>(posLong);
            if (pos == tail)
            {
                RemoveMin();
            }
            else if (pos == head - 1)
            {
                RemoveMax();
            }
            else
            {
                ShiftLeft(pos);
                head = (head - 1 + size) % size;
                CheckNHalve();
            }
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetVec<Data>::Empty() const noexcept
    {
        return ((head - tail) % size == 0);
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &dat) const noexcept
    {
        if (Empty())
        {
            return false;
        }
        else
        {
            return (BinarySearch(dat) != -1);
        }
    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        Vector<Data> *tmp = new Vector<Data>(INIT_SIZE);
        vector = *tmp;
        size = INIT_SIZE;
        delete tmp;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return vector[(tail + index) % size];
    }

    template <typename Data>
    void SetVec<Data>::Resize(ulong newSize)
    {
        Vector<Data> newVector(newSize);
        ulong i = 0;
        for (ulong j = tail; j != head; j = (j + 1) % size)
        {
            newVector[i++] = vector[j];
        }
        vector = std::move(newVector);
        tail = 0;
        head = i;
        size = newSize;
    }

    template <typename Data>
    ulong SetVec<Data>::Size() const noexcept
    {
        return (head - tail) % size;
    }

    template <typename Data>
    ulong SetVec<Data>::FindInsertIndex(const Data &dat) const
    {
        ulong current = tail;
        ulong next = (current + 1) % size;
        while (current != head)
        {
            if (vector[current] > dat)
            {
                return current;
            }
            current = next;
            next = (current + 1) % size;
        }
        return head;
    }

    template <typename Data>
    ulong SetVec<Data>::FindElementIndex(const Data &dat) const
    {
        ulong index = tail;
        while (index != head)
        {
            if (vector[index] == dat)
            {
                return index;
            }
            index = (index + 1) % size;
        }
        return index;
    }

    template <typename Data>
    void SetVec<Data>::InsertAtIndex(const Data &dat)
    {
        ulong pos = FindInsertIndex(dat);
        ShiftRight(pos);
        vector[pos] = dat;
        head = (head + 1) % size;
    }

    template <typename Data>
    void SetVec<Data>::InsertAtIndex(Data &&dat)
    {
        ulong pos = FindInsertIndex(dat);
        ShiftRight(pos);
        vector[pos] = std::move(dat);
        head = (head + 1) % size;
    }

    template <typename Data>
    void SetVec<Data>::PreOrderTraverse(const TraverseFun func) const
    {
        ulong index = tail;
        while (index != head)
        {
            func(vector[index]);
            index = (index + 1) % size;
        }
    }

    template <typename Data>
    void SetVec<Data>::PostOrderTraverse(const TraverseFun func) const
    {
        ulong index = head;
        while (index != tail)
        {
            index = (index - 1 + size) % size;
            func(vector[index]);
        }
    }

    template <typename Data>
    long SetVec<Data>::BinarySearch(const Data &target) const
    {
        ulong left = tail;
        ulong right = (head - 1 + size) % size;

        while ((left % size) != ((right + 1) % size))
        {
            ulong dist = (right - left + size) % size;
            ulong mid = (left + dist / 2) % size;

            if (vector[mid] == target)
            {
                return mid;
            }
            else if (vector[mid] < target)
            {
                left = (mid + 1) % size;
            }
            else
            {
                right = (mid - 1 + size) % size;
            }
        }
        return -1;
    }

    template <typename Data>
    void SetVec<Data>::CheckNHalve()
    {
        if (Size() <= size / 4 && size > INIT_SIZE)
            Resize(size / 2);
    }

    template <typename Data>
    void SetVec<Data>::CheckNDouble()
    {
        if (Size() + 1 > (size / 2))
            Resize(size * 2);
    }

    template <typename Data>
    void SetVec<Data>::ShiftRight(ulong pos)
    {
        for (ulong i = head; i != pos; i = (i - 1 + size) % size)
        {
            vector[i] = vector[(i - 1 + size) % size];
        }
    }

    template <typename Data>
    void SetVec<Data>::ShiftLeft(ulong pos)
    {
        for (ulong i = pos; i != head; i = (i + 1) % size)
        {
            vector[i] = vector[(i + 1) % size];
        }
    }
}