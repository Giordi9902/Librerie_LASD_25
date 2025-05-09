
namespace lasd
{
    template <typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data> &con)
    {
        con.Traverse(
            [this](const Data &currdata)
            {
                if (!Exists(currdata))
                {
                    Insert(currdata);
                }
            });
    }

    template <typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data> &&con)
    {
        con.Map(
            [this](const Data &currdata)
            {
                if (!Exists(currdata))
                {
                    Insert(std::move(currdata));
                }
            });
    }

    template <typename Data>
    SetLst<Data>::SetLst(const SetLst<Data> &con)
    {
        tail = head = nullptr;
        Node *current = con.head;
        while (current != nullptr)
        {
            Insert(current->val);
            current = current->next;
        }
    }

    template <typename Data>
    SetLst<Data>::SetLst(SetLst<Data> &&con) noexcept
    {
        std::swap(size, con.size);
        std::swap(head, con.head);
        std::swap(tail, con.tail);
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(const SetLst<Data> &con)
    {
        if (this != con)
        {
            List<Data>::Clear();
            Node *current = con.head;
            while (current != nullptr)
            {
                Insert(current->val);
                current = current->next;
            }
        }
        return *this;
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(SetLst<Data> &&con) noexcept
    {
        List<Data>::Clear();
        std::swap(size, con.size);
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        return *this;
    }

    template <typename Data>
    bool SetLst<Data>::operator==(const SetLst<Data> &con) const noexcept
    {
        if (size != con.size)
        {
            return false;
        }

        Node *thisNode = head;
        Node *otherNode = con.head;

        while (thisNode != nullptr)
        {
            if (thisNode->val != otherNode->val)
            {
                return false;
            }
            thisNode = thisNode->next;
            otherNode = otherNode->next;
        }

        return true;
    }

    template <typename Data>
    inline bool SetLst<Data>::operator!=(const SetLst<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetLst<Data>::Min() const
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }
        else
        {
            return List<Data>::Front();
        }
    }

    template <typename Data>
    const Data &SetLst<Data>::Max() const
    {
        if (List<Data>::Empty())
            throw std::length_error("The set is empty");
        else
            return List<Data>::Back();
    }

    template <typename Data>
    bool SetLst<Data>::Exists(const Data &dat) const noexcept
    {
        if (!List<Data>::Empty())
        {
            Node *currentNode = head;
            while (currentNode != nullptr)
            {
                if (currentNode->val == dat)
                {
                    return true;
                }
                currentNode = currentNode->next;
            }
        }
        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::Predecessor(const Data &dat) const
    {
        Node *predecessor = nullptr;
        if (!List<Data>::Empty())
        {
            Node *current = head;
            while (current != nullptr && current->val < dat)
            {
                predecessor = current;
                current = current->next;
            }
        }
        if (predecessor == nullptr)
        {
            throw std::length_error("No predecessor found");
        }
        else
        {
            return predecessor->val;
        }
    }

    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        if (!Exists(dat))
        {
            Node *prev = FindPredecessorNode(dat);
            if (List<Data>::Empty() || prev == nullptr)
            {
                List<Data>::InsertAtFront(dat);
            }
            else if (prev == tail)
            {
                List<Data>::InsertAtBack(dat);
            }
            else
            {
                Node *newNode = new Node(dat);
                newNode->next = prev->next;
                prev->next = newNode;
                size++;
            }
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        if (!Exists(dat))
        {
            Node *prev = FindPredecessorNode(dat);
            if (List<Data>::Empty() || prev == nullptr)
            {
                List<Data>::InsertAtFront(std::move(dat));
            }
            else if (prev == tail)
            {
                List<Data>::InsertAtBack(std::move(dat));
            }
            else
            {
                Node *newNode = new Node(std::move(dat));
                newNode->next = prev->next;
                prev->next = newNode;
                size++;
            }
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetLst<Data>::Remove(const Data &dat)
    {
        if (!size)
            return false;

        if (head->val == dat)
        {
            List<Data>::RemoveFromFront();
            return true;
        }

        Node *tmp = head->next;
        Node *prev = head;

        while (tmp != nullptr)
        {

            if (tmp->val == dat)
            {
                prev->next = tmp->next;
                tmp->next ? tmp->next = nullptr : tail = prev;
                delete tmp;
                --size;
                return true;
            }
            prev = tmp;
            tmp = tmp->next;
        }

        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::Successor(const Data &dat) const
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("Set is empty");
        }

        Node *current = head;
        while (current != nullptr && current->val <= dat)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            throw std::length_error("No successor found");
        }

        return current->val;
    }

    template <typename Data>
    const Data SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        Node *successor = FindSuccessorNode(dat);
        if (!List<Data>::Empty() && successor != nullptr)
        {
            Data value = successor->val;
            Remove(value);
            return value;
        }
        else
        {
            throw std::length_error("No successor found");
        }
    }

    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        Node *successor = FindSuccessorNode(dat);
        if (successor != nullptr)
        {
            Remove(successor->val);
        }
        else
        {
            throw std::length_error("No successor found");
        }
    }

    template <typename Data>
    const Data SetLst<Data>::PredecessorNRemove(const Data &dat)
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("Set is empty");
        }

        Node *predecessor = FindPredecessorNode(dat);
        if (predecessor != nullptr)
        {
            Data value = predecessor->val;
            Remove(value);
            return value;
        }
        else
        {
            throw std::length_error("No predecessor found");
        }
    }

    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        Node *predecessor = FindPredecessorNode(dat);
        if (predecessor != nullptr)
        {
            Remove(predecessor->val);
        }
        else
        {
            throw std::length_error("No predecessor found");
        }
    }

    template <typename Data>
    const Data SetLst<Data>::MinNRemove()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("This set is empty");
        }
        else
        {
            return List<Data>::FrontNRemove();
        }
    }

    template <typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("This set is empty");
        }
        else
        {
            List<Data>::RemoveFromFront();
        }
    }

    template <typename Data>
    const Data SetLst<Data>::MaxNRemove()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("This set is empty");
        }
        else
        {
            return List<Data>::BackNRemove();
        }
    }

    template <typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("This set is empty");
        }
        else
        {
            List<Data>::RemoveFromBack();
        }
    }

    template <typename Data>
    typename SetLst<Data>::Node *SetLst<Data>::FindPredecessorNode(const Data &dat) const noexcept
    {
        // Empty list: no predecessor
        if (head == nullptr)
        {
            return nullptr;
        }

        // Target is less than or equal to the head: no predecessor in a sorted set
        if (dat <= head->val)
        {
            return nullptr;
        }

        Node *current = head;
        Node *prev = nullptr;

        // Iterate through the list
        while (current != nullptr && current->val < dat)
        {
            prev = current;
            current = current->next;
        }

        // 'prev' will point to the last node whose value is less than 'dat'
        return prev;
    }

    template <typename Data>
    typename SetLst<Data>::Node *SetLst<Data>::FindSuccessorNode(const Data &dat) const noexcept
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->val > dat)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    template <typename Data>
    SetLst<Data>::~SetLst()
    {
        delete head;
        head = tail = nullptr;
        size = 0;
    }
}
