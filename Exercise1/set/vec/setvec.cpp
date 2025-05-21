namespace lasd
{
    // Definizione di ulong se non già presente
#ifndef LASD_ULONG_DEFINED
#define LASD_ULONG_DEFINED
    using ulong = unsigned long;
#endif

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
        while (index1 != head)
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
        Data min =Min();
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
        Data max = Max();
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

    }

    template <typename Data>
    const Data SetVec<Data>::PredecessorNRemove(const Data &dat)
    {

    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &dat)
    {
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &dat) const
    {

    }

    template <typename Data>
    const Data SetVec<Data>::SuccessorNRemove(const Data &dat)
    {

    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &dat)
    {

    }

    template <typename Data>
    bool SetVec<Data>::IsLeftShiftMoreEfficient(ulong pos) const noexcept
    {

    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &dat)
    {

    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&dat)
    {

    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &dat)
    {

    }

    template <typename Data>
    bool SetVec<Data>::Empty() const noexcept
    {
        return (Size()==0);
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &dat) const noexcept
    {

    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        vector = Vector<Data>(INIT_SIZE);
        size = INIT_SIZE;
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= Size())
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
    ulong SetVec<Data>::BinarySearch(const Data &target) const noexcept
    {

    }

    template <typename Data>
    void SetVec<Data>::PrintVector() const noexcept
    {
        std::cout << "Tail: " << tail << ", Size: " << this->Size() << ", Head: " << head << std::endl;
        for (ulong index = 0; index < vector.Size(); index++)
        {
            std::cout << "Index: " << index << ", Value: ";
            std::cout << vector[index] << " ";
        }
    }

    template <typename Data>
    void SetVec<Data>::ShiftLeftTo(ulong pos)
    {

    }

    template <typename Data>
    void SetVec<Data>::ShiftRightTo(ulong pos)
    {

    }

}