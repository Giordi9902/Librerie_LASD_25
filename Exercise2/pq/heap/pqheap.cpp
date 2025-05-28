
namespace lasd
{
    template <typename Data>
    PQHeap<Data> &PQHeap<Data>::operator=(const PQHeap<Data> &pq)
    {
        if (this != &pq)
        {
            heap = pq.heap;
        }
        return *this;
    }

    template <typename Data>
    PQHeap<Data> &PQHeap<Data>::operator=(PQHeap<Data> &&pq) noexcept
    {
        if (this != &pq)
        {
            heap = std::move(pq.heap);
        }
        return *this;
    }

    template <typename Data>
    const Data &PQHeap<Data>::Tip() const
    {
        if (size == 0)
        {
            throw std::length_error("Priority queue is empty.");
        }
        return heap[0];
    }

    template <typename Data>
    void PQHeap<Data>::RemoveTip()
    {
        if (size == 0)
            throw std::length_error("Priority queue is empty.");
        std::swap(heap[0], heap[size - 1]);
        size--;
        heap.Resize(size);
        heap.HeapifyUp(size-1);
    }

    template <typename Data>
    Data PQHeap<Data>::TipNRemove()
    {
        if (size == 0)
        {
            throw std::length_error("Priority queue is empty.");
        }
        Data tip = heap[0];
        RemoveTip();
        return tip;
    }

    template <typename Data>
    void PQHeap<Data>::Insert(const Data &key)
    {
        heap.Resize(size + 1);
        heap[size - 1] = key;
        heap.HeapifyUp(size - 1);
    }

    template <typename Data>
    void PQHeap<Data>::Insert(Data &&key)
    {
        heap.Resize(size + 1);
        heap[size - 1] = std::move(key);
        heap.HeapifyUp(size - 1);
    }

    template <typename Data>
    void PQHeap<Data>::Change(ulong index, const Data &key)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }
        Data oldKey = heap[index];
        heap[index] = key;
        if (key > oldKey) {
            heap.HeapifyUp(index);
        } else if (key < oldKey) {
            heap.Heapify();
        }
    }

    template <typename Data>
    void PQHeap<Data>::Change(ulong index, Data &&key)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }
    Data oldKey = heap[index];
       heap[index] = std::move(key);
        if (heap[index] > oldKey) {
            heap.HeapifyUp(index);
        } else if (heap[index] < oldKey) {
            heap.Heapify();
        }
    }

    template <typename Data>
    void PQHeap<Data>::Clear()
    {
        size = 0;
        heap.Clear();
    }

    template <typename Data>
    const Data &PQHeap<Data>::operator[](const ulong index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range.");
        }
        return heap[index];
    }

}
