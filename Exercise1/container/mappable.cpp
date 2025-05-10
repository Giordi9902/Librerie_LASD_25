
namespace lasd
{
    template <typename Data>
    void PreOrderMappableContainer<Data>::Map(const MapFun fun)
    {
        PreOrderMap(fun);
    }

    template <typename Data>
    void PostOrderMappableContainer<Data>::Map(const MapFun fun)
    {
        PostOrderMap(fun);
    }

}
