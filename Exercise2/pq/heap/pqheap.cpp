
namespace lasd
{

    template <typename Data>
    PQHeap<Data>::PQHeap(const TraversableContainer<Data> &container) : HeapVec<Data>(container)
    {
        capacity = container.Size();
    }

    template <typename Data>
    PQHeap<Data>::PQHeap(MappableContainer<Data> &&container) : HeapVec<Data>(std::move(container))
    {
        capacity = container.Size();
    }

    template <typename Data>
    PQHeap<Data>::PQHeap(const PQHeap<Data> &other)
        : HeapVec<Data>(other)
    {
        capacity = other.capacity;
    }

    template <typename Data>
    PQHeap<Data>::PQHeap(PQHeap<Data> &&other) noexcept
        : HeapVec<Data>(std::move(other))
    {
        std::swap(capacity, other.capacity);
    }

    template <typename Data>
    PQHeap<Data> &PQHeap<Data>::operator=(const PQHeap<Data> &other)
    {
        HeapVec<Data>::operator=(other);
        capacity = other.capacity;
        return *this;
    }

    template <typename Data>
    PQHeap<Data> &PQHeap<Data>::operator=(PQHeap<Data> &&other) noexcept
    {
        HeapVec<Data>::operator=(std::move(other));
        std::swap(capacity, other.capacity);
        return *this;
    }

    template <typename Data>
    const Data &PQHeap<Data>::Tip() const
    {
        if (this->Empty())
        {
            throw std::length_error("Priority queue is empty.");
        }

        return elements[0];
    }

    template <typename Data>
    void PQHeap<Data>::RemoveTip()
    {
        if (this->Empty())
        {
            throw std::length_error("Priority queue is empty.");
        }

        std::swap(elements[0], elements[size - 1]);
        size--;
        HeapVec<Data>::Heapify();
        if (size <= capacity / 4)
        {
            Resize(capacity / 2);
        }
    }

    template <typename Data>
    Data PQHeap<Data>::TipNRemove()
    {
        if (this->Empty())
        {
            throw std::length_error("Priority queue is empty.");
        }

        Data val = elements[0];
        RemoveTip();
        return val;
    }

    template <typename Data>
    void PQHeap<Data>::Insert(const Data &val)
    {
        if(capacity==0){
            Resize(INIT_SIZE);
            elements[0] = val;
            size++;
            return;
        }
        else if (IsFull() || size + 1 > capacity/2)
        {
            Resize(capacity * 2);
        }
        size++;
        elements[size-1] = val;
        HeapifyUp(size - 1);
    }

    template <typename Data>
    bool PQHeap<Data>::IsFull()
    {
        return size == capacity;
    }

    template <typename Data>
    void PQHeap<Data>::Insert(Data &&val)
    {
        if(capacity==0){
            Resize(INIT_SIZE);
            elements[0] = std::move(val);
            size++;
            return;
        }
        else if (IsFull() || size + 1 > capacity/2)
        {
            Resize(capacity * 2);
        }
        size++;
        elements[size-1] = std::move(val);
        HeapifyUp(size - 1);
    }

    template <typename Data>
    void PQHeap<Data>::Change(ulong index, const Data &val)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }

        elements[index] = val;
        HeapifyUp(index);
        HeapVec<Data>::Heapify();
    }

    template <typename Data>
    void PQHeap<Data>::Change(ulong index, Data &&val)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }

        elements[index] = std::move(val);
        HeapifyUp(index);
    }

    template <typename Data>
    void PQHeap<Data>::Clear()
    {
        HeapVec<Data>::Clear();
        capacity = 0;
    }

    template <typename Data>
    void PQHeap<Data>::HeapifyUp(ulong index)
    {
        ulong i = index;
        while (i > 0)
        {
            ulong parent = HeapVec<Data>::Parent(i);
            if (elements[i] > elements[parent])
            {
                std::swap(elements[i], elements[parent]);
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    template <typename Data>
    void PQHeap<Data>::Resize(ulong newDim)
    {
        Data* newelements = new Data[newDim];
        ulong limit = std::min(size, newDim);
        for (ulong i = 0; i < limit; ++i)
        {
            std::swap(elements[i], newelements[i]);
        }
        std::swap(elements, newelements);
        delete[] newelements;
        capacity = newDim;
    }

}
