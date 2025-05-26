
namespace lasd
{

    template <typename Data>
    HeapVec<Data>::HeapVec(const TraversableContainer<Data> &con)
    {
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(MappableContainer<Data>&& con)
    {
    }

    template <typename Data>
    HeapVec<Data>::HeapVec(const HeapVec<Data>& con)
    {

    }

    template <typename Data>
    HeapVec<Data>::HeapVec(HeapVec<Data>&& con)
    {

    }

    template <typename Data>
    HeapVec<Data>& HeapVec<Data>::operator=(const HeapVec<Data>&con){

    }

    template <typename Data>
    HeapVec<Data>& HeapVec<Data>::operator=(HeapVec<Data>&&con) noexcept {

    }

    template <typename Data>
    bool HeapVec<Data>::operator==(const HeapVec<Data>&con) const noexcept {

    }

    template <typename Data>
    bool HeapVec<Data>::operator!=(const HeapVec<Data>&con) const noexcept {

    }

    template <typename Data>
    bool HeapVec<Data>::IsHeap() const noexcept {

    }

    template <typename Data>
    void HeapVec<Data>::Heapify() noexcept {

    }

    template <typename Data>
    void HeapVec<Data>::HeapSort() noexcept {

    }

}
