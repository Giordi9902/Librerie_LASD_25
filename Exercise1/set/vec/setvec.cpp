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
                     { Insert(dat); });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) : vector(con.Size() * 2), tail(0)
    {
        size = vector.Size();
        con.Map([this](const Data &dat)
                { Insert(std::move(dat)); });
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
        if (Empty() || dat <= vector[tail])
        {
            throw std::length_error("No predecessor found");
        }
        ulong index = BinarySearch(dat);
        if (index == tail)
        {
            throw std::length_error("No predecessor found");
        }
        ulong predecessorIndex = (index - 1 + size) % size;
        return vector[predecessorIndex];
    }

    template <typename Data>
    const Data SetVec<Data>::PredecessorNRemove(const Data &dat)
    {
        if (Empty() || dat <= vector[tail])
        {
            throw std::length_error("No predecessor found");
        }
        ulong index = BinarySearch(dat);
        if (index == tail)
        {
            throw std::length_error("No predecessor found");
        }
        ulong predecessorIndex = (index - 1 + size) % size;
        Data predecessor = vector[predecessorIndex];
        RemoveElement(predecessorIndex);
        return predecessor;
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &dat)
    {
        if (Empty() || dat <= vector[tail])
        {
            throw std::length_error("No predecessor found");
        }
        ulong index = BinarySearch(dat);
        if (index == tail)
        {
            throw std::length_error("No predecessor found");
        }
        ulong predecessorIndex = (index - 1 + size) % size;
        RemoveElement(predecessorIndex);
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &dat) const
    {
        if (Empty() || dat >= vector[(head - 1 + size) % size])
        {
            throw std::length_error("No successor found");
        }
        ulong index = BinarySearch(dat);
        ulong successorIndex = (vector[index] == dat ? (index + 1) % size : index);
        return vector[successorIndex];
    }

    template <typename Data>
    const Data SetVec<Data>::SuccessorNRemove(const Data &dat)
    {
        if (Empty() || dat >= vector[(head - 1 + size) % size])
        {
            throw std::length_error("No successor found");
        }
        ulong index = BinarySearch(dat);
        ulong successorIndex = (vector[index] == dat ? (index + 1) % size : index);
        Data successor = vector[successorIndex];
        RemoveElement(successorIndex);
        return successor;
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &dat)
    {
        if (Empty() || dat >= vector[(head - 1 + size) % size])
        {
            throw std::length_error("No successor found");
        }
        ulong index = BinarySearch(dat);
        ulong successorIndex = (vector[index] == dat ? (index + 1) % size : index);
        RemoveElement(successorIndex);
    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &dat)
    {
        if (Empty())
        {
            vector[tail] = dat;
            head = (head + 1) % size;
            return true;
        }

        ulong pos = BinarySearch(dat);
        if (vector[pos] != dat)
        {
            if (dat < vector[tail])
            {
                tail = (tail - 1 + size) % size;
                vector[tail] = dat;
                CheckNDouble();
                return true;
            }
            else
            {
                InsertAtIndex(pos, dat);
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&dat)
    {
        if (Empty())
        {
            vector[tail] = std::move(dat);
            head = (head + 1) % size;
            return true;
        }

        ulong pos = BinarySearch(dat);
        if (vector[pos] != dat)
        {
            if (dat < vector[tail])
            {
                tail = (tail - 1 + size) % size;
                vector[tail] = std::move(dat);
                CheckNDouble();
                return true;
            }
            else
            {
                InsertAtIndex(pos, std::move(dat));
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &dat)
    {

        ulong pos = BinarySearch(dat);
        if (vector[pos] == dat)
        {
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
        return (Size()== 0);
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
            ulong index = BinarySearch(dat);
            return (vector[index] == dat);
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
        return (head - tail + size) % size;
    }

    template <typename Data>
    ulong SetVec<Data>::BinarySearch(const Data &dat) const
    {
        if (Empty())
        {
            return tail;
        }

        long logical_size = (head - tail + size) % size;
        long left = 0;
        long right = logical_size - 1;

        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            ulong mid_index = (tail + mid) % size;

            if (vector[mid_index] == dat)
            {
                return mid_index;
            }
            else if (vector[mid_index] < dat)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return (tail + left) % size;
    }

    template <typename Data>
    void SetVec<Data>::InsertAtIndex(ulong pos, const Data &dat)
    {
        InsertionShiftRight(pos);
        vector[pos] = dat;
        CheckNDouble();
    }

    template <typename Data>
    void SetVec<Data>::InsertAtIndex(ulong pos, Data &&dat)
    {

        InsertionShiftRight(pos);
        vector[pos] = std::move(dat);
        CheckNDouble();
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
    void SetVec<Data>::InsertionShiftRight(ulong pos)
    {
        // Da chiamare durante inserimento per fare spazio verso destra
        for (ulong i = head; i != pos; i = (i - 1 + size) % size)
        {
            vector[i] = vector[(i - 1 + size) % size];
        }
        head = (head + 1) % size;
    }

    template <typename Data>
    void SetVec<Data>::RemovalShiftLeft(ulong pos)
    {
        // Da chiamare durante la rimozione
        for (ulong i = pos; i != head; i = (i + 1) % size)
        {
            vector[i] = vector[(i + 1) % size];
        }
        head = (head - 1 + size) % size;
    }

    template <typename Data>
    void SetVec<Data>::RemoveElement(ulong pos)
    {
        RemovalShiftLeft(pos);
        CheckNHalve();
    }

    template <typename Data>
    void SetVec<Data>::PrintVector() const noexcept
    {
        std::cout << "SetVec's size: " << Size() << std::endl;
        std::cout << "Head: " << head << std::endl;
        std::cout << "Tail: " << tail << std::endl;
        std::cout << std::endl;
        std::cout << "Vector: " << std::endl;
        for (ulong i = 0; i < size; ++i)
        {
            std::cout << "V[" << i << "] = " << vector[i] << std::endl;
        }
        std::cout << std::endl;
    }

}
