
namespace lasd
{

    template <typename Data>
    template <typename Accumulator>
    Accumulator TraversableContainer<Data>::Fold(const FoldFun<Accumulator> func, Accumulator base) const
    {
        Traverse(
            [&base, func](const Data &currData)
            {
                base = func(currData, base);
            });
        return base;
    };

    template <typename Data>
    bool TraversableContainer<Data>::Exists(const Data &data) const noexcept
    {
        bool exists = false;
        Traverse(
            [data, &exists](const Data &currData)
            {
                exists |= (data == currData);
            });
        return exists;
    }

    // PreOrder Traversable Container

    template <typename Data>
    void PreOrderTraversableContainer<Data>::Traverse(const TraverseFun func) const
    {
        PreOrderTraverse(func);
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(const FoldFun<Accumulator> func, Accumulator base) const
    {
        PreOrderTraverse(
            [&base, func](const Data &currData)
            {
                base = func(currData, base);
            });
        return base;
    };

    // PreOrder Traversable Container

    template <typename Data>
    void PostOrderTraversableContainer<Data>::Traverse(const TraverseFun func) const
    {
        PostOrderTraverse(func);
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(const FoldFun<Accumulator> func, Accumulator base) const
    {
        PostOrderTraverse(
            [&base, func](const Data &currData)
            { base = func(currData, base); });
        return base;
    };
}
