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
        long predecessorIndex = GetPredecessorIndex(dat);
        if (predecessorIndex != -1)
            return vector[(ulong)predecessorIndex];
        throw std::length_error("No predecessor found");
    }

    template <typename Data>
    const Data SetVec<Data>::PredecessorNRemove(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        long predecessorIndex = GetPredecessorIndex(dat);
        if (predecessorIndex != -1)
        {
            Data pred = vector[(ulong)predecessorIndex];
            RemoveElement(predecessorIndex);
            return pred;
        }
        throw std::length_error("No predecessor found.");
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        long pos = GetPredecessorIndex(dat);
        if (pos != -1)
        {
            RemoveElement(pos);
            return; // Aggiungi return qui
        }
        throw std::length_error("No predecessor found.");
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &dat) const
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        long successorIndex = GetSuccessorIndex(dat);
        if (successorIndex != -1)
        {
            return vector[(ulong)successorIndex];
        }
        throw std::length_error("No successor found");
    }

    template <typename Data>
    const Data SetVec<Data>::SuccessorNRemove(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        long successorIndex = GetSuccessorIndex(dat);
        if (successorIndex != -1)
        {
            const Data succ = vector[successorIndex];
            RemoveElement(successorIndex);
            return succ;
        }
        throw std::length_error("No successor found");
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &dat)
    {
        if (Empty())
        {
            throw std::length_error("Set is empty");
        }
        long pos = GetSuccessorIndex(dat);
        if (pos != -1)
        {
            RemoveElement(pos);
            return;
        }
        throw std::length_error("No successor found");
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
                RemoveElement(pos);
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
        if (Empty())
        {
            return tail;
        }

        ulong left = tail;
        ulong right = (head - 1 + size) % size;

        if (dat < vector[left])
        {
            return left;
        }
        if (dat > vector[right])
        {
            return head;
        }

        while ((left % size) != ((right + 1) % size))
        {
            ulong dist = (right - left + size) % size;
            ulong mid = (left + dist / 2) % size;

            if (vector[mid] == dat)
            {
                return mid;
            }
            else if (vector[mid] < dat)
            {
                left = (mid + 1) % size;
            }
            else
            {
                right = (mid - 1 + size) % size;
            }
        }

        return left;
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

    template <typename Data>
    void SetVec<Data>::RemoveElement(ulong pos)
    {
        ShiftLeft(pos);
        head = (head - 1 + size) % size;
        CheckNHalve();
    }

    template <typename Data>
    long SetVec<Data>::GetPredecessorIndex(const Data &target) const
    {
        if (Empty() || vector[tail] >= target)
        {
            return -1;
        }

        ulong left = tail;
        ulong right = (head - 1 + size) % size;

        long result = -1;
        while ((left % size) != ((right + 1) % size))
        {
            ulong dist = (right - left + size) % size;
            ulong mid = (left + dist / 2) % size;

            if (vector[mid] < target)
            {
                result = mid;
                left = (mid + 1) % size;
            }
            else
            {
                right = (mid - 1 + size) % size;
            }
        }

        if (vector[left] < target)
        {
            result = left;
        }
        else if (result == -1 && left != tail && vector[(left - 1 + size) % size] < target)
        {
            result = (left - 1 + size) % size;
        }

        return result;
    }

    template <typename Data>
    long SetVec<Data>::GetSuccessorIndex(const Data &target) const
    {
        if (Empty() || vector[(head-1+size)%size] <= target)
        {
            return -1;
        }

        ulong left = tail;
        ulong right = (head - 1 + size) % size;

        long result = -1;
        while ((left % size) != ((right + 1) % size))
        {
            ulong dist = (right - left + size) % size;
            ulong mid = (left + dist / 2) % size;

            if (vector[mid] > target)
            {
                result = mid;
                right = (mid - 1 + size) % size;
            }
            else
            {
                left = (mid + 1) % size;
            }
        }

        if ((vector[right] > target) && (result == -1))
        {
            result = right;
        }

        return result;
    }
}