#include <utility>
namespace lasd
{

    template <typename Data>
    HeapVec<Data>::HeapVec() : vector(INIT_SIZE)
    {
        size = INIT_SIZE;
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(const TraversableContainer<Data> &con) : vector(con)
    {
        size = vector.Size();
        Heapify();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(MappableContainer<Data> &&con) : vector(std::move(con))
    {
        size = vector.Size();
        Heapify();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(const HeapVec<Data> &con)
    {
        vector = con.vector;
        size = con.size;
        Heapify();
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(HeapVec<Data> &&con) noexcept
    {
        vector = std::move(con.vector);
        std::swap(size, con.size);
        Heapify();
    }

    template <typename Data>
    HeapVec<Data> &HeapVec<Data>::operator=(const HeapVec<Data> &con)
    {
        vector = con.vector;
        size = con.size;
        return *this;
    }

    template <typename Data>
    HeapVec<Data> &HeapVec<Data>::operator=(HeapVec<Data> &&con) noexcept
    {
        std::swap(vector,con.vector);
        size = std::exchange(con.size, 0);
        return *this;
    }

    template <typename Data>
    bool HeapVec<Data>::operator==(const HeapVec<Data> &con) const noexcept
    {
        return vector == con.vector;
    }

    template <typename Data>
    bool HeapVec<Data>::operator!=(const HeapVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    bool HeapVec<Data>::IsHeap() const noexcept
    {
        if (size <= 1)
        {
            return true;
        }
        for (ulong i = 0; i < size / 2; ++i)
        {
            ulong left = 2 * i + 1;
            ulong right = 2 * i + 2;
            if (left < size && vector[i] < vector[left])
            {
                return false;
            }
            if (right < size && vector[i] < vector[right])
            {
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    void HeapVec<Data>::Heapify() noexcept
    {
        for (long i = (size / 2) - 1; i >= 0; --i)
        {
            Heapify(size, i);
        }
    }

    template <typename Data>
    void HeapVec<Data>::HeapSort() noexcept
    {
        Heapify();
        for (long i = size - 1; i > 0; --i)
        {
            std::swap(vector[0], vector[i]);
            Heapify(i, 0);
        }
    }

    template <typename Data>
    void HeapVec<Data>::Heapify(ulong n, ulong i) noexcept
    {
        ulong largest = i;
        ulong left = 2 * i + 1;
        ulong right = 2 * i + 2;

        if (left < n && vector[left] > vector[largest])
        {
            largest = left;
        }
        if (right < n && vector[right] > vector[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            std::swap(vector[i], vector[largest]);
            Heapify(n, largest);
        }
    }

    template <typename Data>
    void HeapVec<Data>::Clear() noexcept
    {
        vector.Clear();
        size = 0;
    }

    template <typename Data>
    const Data &HeapVec<Data>::operator[](ulong index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return vector[index];
    }

    template <typename Data>
    Data &HeapVec<Data>::operator[](ulong index)
    {
        return const_cast<Data &>(static_cast<const HeapVec<Data> *>(this)->operator[](index));
    }

}
