
namespace lasd
{
    template <typename Data>
    inline void PreOrderMappableContainer<Data>::Map(const MapFun fun)
    {
        PreOrderMap(fun);
    }

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(const MapFun fun)
    {
        PostOrderMap(fun);
    }

}
