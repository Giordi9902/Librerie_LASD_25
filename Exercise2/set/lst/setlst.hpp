#ifndef SETLST_HPP
#define SETLST_HPP

#include "../set.hpp"
#include "../../list/list.hpp"

namespace lasd
{

    template <typename Data>
    class SetLst : virtual public Set<Data>,
                   virtual protected List<Data>
    {

    protected:
        using Container::size;
        using List<Data>::head;
        using List<Data>::tail;
        using typename List<Data>::Node;

    public:
        // Default constructor
        SetLst() = default;

        // Specific constructors
        SetLst(const TraversableContainer<Data> &);
        SetLst(MappableContainer<Data> &&);

        // Copy constructor
        SetLst(const SetLst<Data> &);

        // Move constructor
        SetLst(SetLst<Data> &&) noexcept;

        // Destructor
        virtual ~SetLst();

        // Copy assignment
        SetLst<Data> &operator=(const SetLst<Data> &);

        // Move assignment
        SetLst<Data> &operator=(SetLst<Data> &&) noexcept;

        // Comparison operators
        bool operator==(const SetLst<Data> &) const noexcept;
        inline bool operator!=(const SetLst<Data> &) const noexcept;

        // Specific member functions (inherited from OrderedDictionaryContainer)

        const Data &Min() const override;
        const Data MinNRemove() override;
        void RemoveMin() override;

        const Data &Max() const override;
        const Data MaxNRemove() override;
        void RemoveMax() override;

        const Data &Predecessor(const Data &) const override;
        const Data PredecessorNRemove(const Data &) override;
        void RemovePredecessor(const Data &) override;

        const Data &Successor(const Data &) const override;
        const Data SuccessorNRemove(const Data &) override;
        void RemoveSuccessor(const Data &) override;

        // Specific member functions (inherited from DictionaryContainer)

        bool Insert(const Data &) override;
        bool Insert(Data &&) override;
        bool Remove(const Data &) override;

        // Specific member functions (inherited from LinearContainer)

        using List<Data>::operator[];

        // Specific member function (inherited from TestableContainer)

        bool Exists(const Data &) const noexcept;

        // Specific member function (inherited from ClearableContainer)
        using List<Data>::Clear;
        using List<Data>::Traverse;

    protected:
        // Auxiliary functions, if necessary!
        Node *FindPredecessorNode(const Data &,Node**) const noexcept;
        Node *FindSuccessorNode(const Data &,Node**) const noexcept;
        Node* GetNodeAt(Node*,ulong) const noexcept;
        bool BinarySearch(const Data&) const noexcept;
        void AttachNode(Node*,Node*);
        void DetachNode(Node*,Node*);
    };

}

#include "setlst.cpp"

#endif