
namespace lasd
{
    template <typename Data>
    SetLst<Data>::SetLst(const TraversableContainer<Data> &con)
    {
        con.Traverse(
            [this](const Data &currdata)
            {
                Insert(currdata);
            });
    }

    template <typename Data>
    SetLst<Data>::SetLst(MappableContainer<Data> &&con)
    {
        con.Map(
            [this](const Data &currdata)
            {
                Insert(std::move(currdata));
            });
    }

    template <typename Data>
    SetLst<Data>::SetLst(const SetLst<Data> &con) : List<Data>::List(con)
    {
    }

    template <typename Data>
    SetLst<Data>::SetLst(SetLst<Data> &&con) noexcept : List<Data>::List(std::move(con))
    {
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(const SetLst<Data> &con)
    {
        return List<Data>::operator=(con);
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
            return BinarySearch(dat);
        }
        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::Predecessor(const Data &dat) const
    {
        if (!List<Data>::Empty())
        {
            Node *predecessor = FindPredecessorNode(dat, nullptr);
            if (predecessor == nullptr)
            {
                throw std::length_error("No predecessor found");
            }
            else
            {
                return predecessor->val;
            }
        }
        else
        {
            throw std::length_error("Set is empty!");
        }
    }

    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        Node *prev = FindPredecessorNode(dat, nullptr);
        Node *curr = (prev == nullptr) ? head : prev->next;

        if (curr != nullptr && curr->val == dat)
        {
            return false;
        }

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
            AttachNode(newNode,prev);
        }

        return true;
    }

    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        Node *prev = FindPredecessorNode(dat, nullptr);
        Node *curr = (prev == nullptr) ? head : prev->next;

        if (curr != nullptr && curr->val == dat)
        {
            return false;
        }

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
            AttachNode(newNode,prev);
        }

        return true;
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

        Node *prev = FindPredecessorNode(dat, nullptr);
        if (prev != nullptr && prev->next != nullptr && prev->next->val == dat)
        {
            Node *toRemove = prev->next;
            DetachNode(toRemove,prev);
            return true;
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

        Node *successor = FindSuccessorNode(dat, nullptr);
        if (successor == nullptr)
        {
            throw std::length_error("No successor found!");
        }

        return successor->val;
    }

    template <typename Data>
    const Data SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("Set is empty");
        }

        Node *sprev = nullptr;
        Node *successor = FindSuccessorNode(dat, &sprev);

        if (successor == nullptr)
        {
            throw std::length_error("No successor found");
        }

        if (successor == head)
        {
            return List<Data>::FrontNRemove();
        }

        Data value = successor->val;
        DetachNode(successor,sprev);

        return value;
    }

    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        Node *sprev = nullptr;
        Node *successor = FindSuccessorNode(dat, &sprev);

        if (successor != nullptr)
        {
            if (successor == head)
            {
                List<Data>::RemoveFromFront();
            }
            else
            {

                DetachNode(successor,sprev);
            }
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

        Node *pprev = nullptr;
        Node *predecessor = FindPredecessorNode(dat, &pprev);

        if (predecessor == nullptr)
        {
            throw std::length_error("No predecessor found");
        }

        if (predecessor == head)
        {
            return List<Data>::FrontNRemove();
        }

        Data value = predecessor->val;
        DetachNode(predecessor,pprev);

        return value;
    }

    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        Node *pprev = nullptr;
        Node *predecessor = FindPredecessorNode(dat, &pprev);

        if (predecessor == nullptr)
        {
            throw std::length_error("No predecessor found");
        }

        if (predecessor == head)
        {
            List<Data>::RemoveFromFront();
            return;
        }

        DetachNode(predecessor,pprev);
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
    typename SetLst<Data>::Node *SetLst<Data>::FindPredecessorNode(const Data &dat, Node **prev_prev) const noexcept
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        if (dat <= head->val)
        {
            return nullptr;
        }

        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr && current->val < dat)
        {
            if (prev_prev != nullptr)
            {
                *prev_prev = prev;
            }
            prev = current;
            current = current->next;
        }
        return prev;
    }

    template <typename Data>
    typename SetLst<Data>::Node *SetLst<Data>::FindSuccessorNode(const Data &dat, Node **sprev) const noexcept
    {
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->val > dat)
            {
                if (sprev != nullptr)
                {
                    *sprev = prev;
                }
                return current;
            }
            prev = current;
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

    template <typename Data>
    typename SetLst<Data>::Node *SetLst<Data>::GetNodeAt(Node *start, ulong index) const noexcept
    {
        Node *current = start;
        for (ulong i = 0; i < index && current; ++i)
        {
            current = current->next;
        }
        return current;
    }

    template <typename Data>
    bool SetLst<Data>::BinarySearch(const Data &target) const noexcept
    {
        ulong left = 0;
        ulong right = size - 1;
        Node *leftNode = head;

        while (left <= right)
        {
            ulong mid = left + (right - left) / 2;

            Node *midNode = GetNodeAt(leftNode, mid - left);

            if (!midNode)
                return false;

            if (midNode->val == target)
            {
                return true;
            }
            else if (target < midNode->val)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                leftNode = midNode->next;
            }
        }
        return false;
    }

    template <typename Data>
    void SetLst<Data>::AttachNode(Node *newNode, Node *prevNode)
    {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        ++size;
    }

    template <typename Data>
    void SetLst<Data>::DetachNode(Node* toRemove, Node* prevNode)
    {
        prevNode->next = toRemove->next;
        if(toRemove->next == nullptr)
            tail = prevNode;
        toRemove->next = nullptr;
        delete toRemove;
        --size;
    }
}
