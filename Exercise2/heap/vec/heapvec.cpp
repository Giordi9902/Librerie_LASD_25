
namespace lasd
{

    template <typename Data>
    HeapVec<Data>::HeapVec(const TraversableContainer<Data> &con) : SortableVector<Data>(con)
    {
        Heapify();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(MappableContainer<Data> &&con) : SortableVector<Data>(std::move(con))
    {
        Heapify();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(const HeapVec<Data> &heap) : SortableVector<Data>(heap)
    {
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(HeapVec<Data> &&heap) noexcept : SortableVector<Data>(std::move(heap))
    {
    }

    template <typename Data>
    HeapVec<Data> &HeapVec<Data>::operator=(const HeapVec<Data> &con)
    {
        Vector<Data>::operator=(con);
        return *this;
    }

    template <typename Data>
    HeapVec<Data> &HeapVec<Data>::operator=(HeapVec<Data> &&con) noexcept
    {
        Vector<Data>::operator=(std::move(con));
        return *this;
    }

    template <typename Data>
    bool HeapVec<Data>::operator==(const HeapVec<Data> &con) const noexcept
    {
        return Vector<Data>::operator==(con);
    }

    template <typename Data>
    bool HeapVec<Data>::operator!=(const HeapVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    bool HeapVec<Data>::IsHeap() const noexcept
    {
        if (size <= 1) return true;
        for (ulong index = 0; index < size / 2; ++index)
        {
            ulong largest = FindMax(index,size);
            if(largest!=index)
                return false;
        }
        return true;
    }

    template <typename Data>
    void HeapVec<Data>::HeapSort() noexcept
    {
        ulong heapSize = size;
        for (long i = heapSize / 2 - 1; i >= 0; --i) {
            HeapifyNode(i, heapSize);
        }
        for (long i = heapSize - 1; i > 0; --i) {
            std::swap(elements[0], elements[i]);
            heapSize--;
            HeapifyNode(0, heapSize);
        }
    }

    template <typename Data>
    void HeapVec<Data>::HeapifyNode(ulong index, ulong heapSize) noexcept
    {
        ulong largest = FindMax(index,heapSize);
        if(largest!=index){
            std::swap(elements[index],elements[largest]);
            HeapifyNode(largest,heapSize);
        }
    }

    template <typename Data>
    void HeapVec<Data>::Heapify() noexcept
    {
        for (long i = size / 2 - 1; i >= 0; --i)
        {
            HeapifyNode(i, size);
        }
    }

    template <typename Data>
    ulong HeapVec<Data>::Parent(ulong index) const
    {
        if (index == 0)
        {
            return 0;
        }
        return (index - 1) / 2;
    }

    template <typename Data>
    ulong HeapVec<Data>::Left(ulong index) const
    {
        return 2 * index + 1;

    }

    template <typename Data>
    ulong HeapVec<Data>::Right(ulong index) const
    {
        return 2 * index + 2;
    }

    template <typename Data>
    void HeapVec<Data>::Clear()
    {
        SortableVector<Data>::Clear();
        size = 0;
    }

    template <typename Data>
    ulong HeapVec<Data>::FindMax(ulong index, ulong heapsize) const
    {
        ulong largest = index;
        ulong left = Left(index);
        ulong right = Right(index);

        if (left < heapsize && elements[largest] < elements[left]) {
            largest = left;
        }
        if (right < heapsize && elements[largest] < elements[right]) {
            largest = right;
        }
        return largest;
    }

}
