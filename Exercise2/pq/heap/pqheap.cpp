
namespace lasd
{

    template <typename Data>
    PQHeap<Data>::PQHeap(const TraversableContainer<Data> &container) : HeapVec<Data>(container)
    {
    }

    template <typename Data>
    PQHeap<Data>::PQHeap(MappableContainer<Data> &&container) : HeapVec<Data>(std::move(container))
    {
    }

    template <typename Data>
    PQHeap<Data>::PQHeap(const PQHeap<Data> &other)
        : HeapVec<Data>(other)
    {
    }

    template <typename Data>
    PQHeap<Data>::PQHeap(PQHeap<Data> &&other) noexcept
        : HeapVec<Data>(std::move(other))
    {
    }

    template <typename Data>
    PQHeap<Data> &PQHeap<Data>::operator=(const PQHeap<Data> &other)
    {
        HeapVec<Data>::operator=(other);
        return *this;
    }

    template <typename Data>
    PQHeap<Data> &PQHeap<Data>::operator=(PQHeap<Data> &&other) noexcept
    {
        HeapVec<Data>::operator=(std::move(other));
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
        HeapVec<Data>::Heapify();
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
        this->Vector<Data>::Resize(size + 1);
        ulong index = size - 1;
        elements[index] = val;
        HeapifyUp(index);
    }

    template <typename Data>
    void PQHeap<Data>::Insert(Data &&val)
    {
        this->Vector<Data>::Resize(size + 1);
        ulong index = size - 1;
        elements[index] = std::move(val);
        HeapifyUp(index);
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
}
