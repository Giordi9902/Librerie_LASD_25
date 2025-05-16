
#ifndef LIST_HPP
#define LIST_HPP
#include "../container/linear.hpp"

namespace lasd
{

  template <typename Data>
  class List : virtual public MutableLinearContainer<Data>,
               virtual public ClearableContainer
  {

  protected:
    using Container::size;
    struct Node
    {

      Data val{};
      Node *next = nullptr;

      Node() = default;
      Node(const Data &);
      Node(Data &&) noexcept;
      Node(const Node &);
      Node(Node &&) noexcept;

      virtual ~Node();

      inline bool operator==(const Node &) const noexcept;
      inline bool operator!=(const Node &) const noexcept;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

  public:

    List() = default;
    List(const TraversableContainer<Data> &);
    List(MappableContainer<Data> &&);
    List(const List &);
    List(List &&);

    virtual ~List();

    inline List &operator=(const List &);
    inline List &operator=(List &&) noexcept;

    inline bool operator==(const List &) const noexcept;
    inline bool operator!=(const List &) const noexcept;

    void InsertAtFront(const Data &);
    void InsertAtFront(Data &&);

    void RemoveFromFront();
    Data FrontNRemove();

    void InsertAtBack(const Data &);
    void InsertAtBack(Data &&);

    void RemoveFromBack();
    Data BackNRemove();

    inline const Data &operator[](const ulong) const override;
    inline const Data &Front() const override;
    inline const Data &Back() const override;

    inline Data &operator[](ulong) override;
    inline Data &Front() override;
    inline Data &Back() override;

    using typename MappableContainer<Data>::MapFun;
    void Map(const MapFun) override;

    void PreOrderMap(const MapFun) override;
    void PostOrderMap(const MapFun) override;

    using typename TraversableContainer<Data>::TraverseFun;
    void Traverse(const TraverseFun) const override;
    void PreOrderTraverse(const TraverseFun) const override;
    void PostOrderTraverse(const TraverseFun) const override;

    inline void Clear() override;

  protected:

    void PreOrderTraverse(const TraverseFun, Node *) const;
    void PostOrderTraverse(const TraverseFun, Node *) const;
    void PreOrderMap(const MapFun, Node *) const;
    void PostOrderMap(const MapFun, Node *) const;
    Node* FindPenultimateNode() const;

  };

}

#include "list.cpp"

#endif
