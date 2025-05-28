
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
        for (ulong i = 0; i < size / 2; ++i)
        {
            ulong leftChild = Left(i);
            ulong rightChild = Right(i);
            if (leftChild < size && elements[i] < elements[leftChild])
                return false;
            if (rightChild < size && elements[i] < elements[rightChild])
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
        ulong largest = index;
        ulong left = Left(index);
        ulong right = Right(index);

        if (left < heapSize && elements[largest] < elements[left]) {
            largest = left;
        }
        if (right < heapSize && elements[largest] < elements[right]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(elements[index], elements[largest]);
            HeapifyNode(largest, heapSize);
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
            return 0; // Root has no parent
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
    void HeapVec<Data>::HeapifyUp(ulong index)
    {
        while (index != 0 && Parent(index) < size && elements[Parent(index)] < elements[index]) {
            std::swap(elements[Parent(index)], elements[index]);
            index = Parent(index);
        }
    }

}
