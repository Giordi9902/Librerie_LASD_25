
namespace lasd
{

    template <typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data> &con)
    {
        con.Traverse(
            ([this](const Data &dat)
             {
                if (!Exists(dat))
                {
                    InsertInOrder(dat);
                } }));
    }

    template <typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data> &&con)
    {
        con.Map(
            ([this](Data &dat)
             {
                if (!Exists(dat))
                {
                    InsertInOrder(std::move(dat));
                } }));
    }

    template <typename Data>
    SetLst<Data>::SetLst(const SetLst<Data> &con)
    {
        con.Traverse(
            ([this](const Data &dat)
             {
                if (!Exists(dat))
                {
                    InsertInOrder(dat);
                } }));
    }

    template <typename Data>
    SetLst<Data>::SetLst(SetLst<Data> &&con) noexcept
    {
        con.Map(
            ([this](Data &dat)
             {
                if (!Exists(dat))
                {
                    InsertInOrder(std::move(dat));
                } }));
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(const SetLst<Data> &con)
    {
        Clear();
        con.Traverse(
            ([this](const Data &dat)
             {
                if (!Exists(dat))
                    InsertInOrder(dat); }));
        return *this;
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(SetLst<Data> &&con) noexcept
    {
        Clear();
        con.Map(
            ([this](Data &dat)
             {
                if (!Exists(dat))
                {
                    InsertInOrder(std::move(dat));
                } }));
        return *this;
    }

    template <typename Data>
    bool SetLst<Data>::operator==(const SetLst<Data> &con) const noexcept
    {
        if (size != con.size)
        {
            return false;
        }
        bool isEqual = true;
        con.Traverse(
            ([&](const Data &dat)
             {
                if (!(*this).Exists(dat))
                    isEqual = false; }));
        return isEqual;
    }

    template <typename Data>
    bool SetLst<Data>::operator!=(const SetLst<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetLst<Data>::Min() const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        return head->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::MinNRemove()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        const Data &minValue = head->val;
        RemoveNode(*head);
        return minValue;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        if (head == tail)
        {
            RemoveNode(*head);
            head = tail = nullptr;
        }
        else
        {
            RemoveNode(*head);
            head = head->next;
        }
    }

    template <typename Data>
    const Data &SetLst<Data>::Max() const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        const Data& max = tail->val;
        return max;
    }

    template <typename Data>
    const Data &SetLst<Data>::MaxNRemove()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        const Data &maxValue = tail->val;
        RemoveMax();
        return maxValue;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        if (tail == head)
        {
            RemoveNode(*tail);
            head = tail = nullptr;
        }
        else
        {
            typename List<Data>::Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            RemoveNode(*tail);
            tail = current;
            tail->next = nullptr;
        }
    }

    template <typename Data>
    const Data &SetLst<Data>::Predecessor(const Data &dat) const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *current = head;
        while (current != nullptr && current->val < dat)
        {
            current = current->next;
        }
        return current->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::PredecessorNRemove(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *current = head;
        while (current != nullptr && current->val < dat)
        {
            current = current->next;
        }
        const Data &predValue = current->val;
        RemoveNode(*current);
        return predValue;
    }

    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *current = head;
        while (current != nullptr && current->val < dat)
        {
            current = current->next;
        }
        RemoveNode(*current);
    }

    template <typename Data>
    const Data &SetLst<Data>::Successor(const Data &dat) const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *current = head;
        while (current != nullptr && current->val <= dat)
        {
            current = current->next;
        }
        return current->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *current = head;
        while (current != nullptr && current->val <= dat)
        {
            current = current->next;
        }
        const Data &succValue = current->val;
        RemoveNode(*current);
        return succValue;
    }

    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *current = head;
        while (current != nullptr && current->val <= dat)
        {
            current = current->next;
        }
        RemoveNode(*current);
    }

    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        if (Exists(dat))
        {
            return false;
        }
        else
        {
            InsertInOrder(dat);
            return true;
        }
    }

    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        if (Exists(dat))
        {
            return false;
        }
        else
        {
            InsertInOrder(std::move(dat));
            return true;
        }
    }

    template <typename Data>
    bool SetLst<Data>::Remove(const Data &dat)
    {
        if (Exists(dat))
        {
            typename List<Data>::Node *current = head;
            while (current != nullptr)
            {
                if (current->val == dat)
                {
                    RemoveNode(*current);
                    return true;
                }
                current = current->next;
            }
        }
        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::operator[](ulong idx) const
    {
        if (idx >= size)
        {
            throw std::out_of_range("Error: index out of range");
        }
        return List<Data>::operator[](idx);
    }

    template <typename Data>
    void SetLst<Data>::RemoveNode(typename List<Data>::Node &node)
    {
        if (&node == head)
        {
            typename List<Data>::Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            typename List<Data>::Node *current = head;
            while (current->next != &node)
            {
                current = current->next;
            }
            current->next = node.next;
            if (&node == tail)
            {
                tail = current;
            }
            delete &node;
        }
        --size;
    }

    template <typename Data>
    void SetLst<Data>::InsertAfter(typename List<Data>::Node &prev, const Data &dat)
    {
        typename List<Data>::Node *newNode = new typename List<Data>::Node(dat);
        newNode->next = prev.next;
        prev.next = newNode;
    }

    template <typename Data>
    void SetLst<Data>::InsertAfter(typename List<Data>::Node &prev, Data &&dat)
    {
        typename List<Data>::Node *newNode = new typename List<Data>::Node(std::move(dat));
        newNode->next = prev.next;
        prev.next = newNode;
    }

    template <typename Data>
    void SetLst<Data>::InsertInOrder(const Data &dat)
    {
        typename List<Data>::Node *current = head;
        typename List<Data>::Node *prev = nullptr;
        while (current != nullptr && current->val < dat)
        {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr)
        {
            head = new typename List<Data>::Node(dat);
            head->next = current;
        }
        else
        {
            InsertAfter(*prev, dat);
        }
        ++size;
    }

    template <typename Data>
    void SetLst<Data>::InsertInOrder(Data &&dat)
    {
        typename List<Data>::Node *current = head;
        typename List<Data>::Node *prev = nullptr;
        while (current != nullptr && current->val < dat)
        {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr)
        {
            head = new typename List<Data>::Node(std::move(dat));
            head->next = current;
        }
        else
        {
            InsertAfter(*prev, std::move(dat));
        }
        ++size;
    }
}
