
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
        size = con.size;
        head = con.head;
        tail = con.tail;
    }

    template <typename Data>
    SetLst<Data>::SetLst(SetLst<Data> &&con)
    {
        std::swap(size, con.size);
        std::swap(head, con.head);
        std::swap(tail, con.tail);
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(const SetLst<Data> &con)
    {
        Clear();
        size = con.size;
        head = con.head;
        tail = con.tail;
        return *this;
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(SetLst<Data> &&con) noexcept
    {
        Clear();
        std::swap(size, con.size);
        std::swap(head, con.head);
        std::swap(tail, con.head);
        return *this;
    }

    template <typename Data>
    bool SetLst<Data>::operator==(const SetLst<Data> &con) const noexcept
    {
        return List<Data>::operator==(con);
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
            return head->val;
        }
    }

    template <typename Data>
    const Data &SetLst<Data>::Max() const
    {
        if (List<Data>::Empty())
            throw std::length_error("The set is empty");
        else
            return tail->val;
    }

    template <typename Data>
    bool SetLst<Data>::Exists(const Data &dat) const noexcept
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            if (currentNode->val != dat)
            {
                currentNode = currentNode->next;
            }
            return true;
        }
        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::Predecessor(const Data &dat) const
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }

        Node *currentNode = head;
        Node *predecessor = nullptr;

        while (currentNode != nullptr && currentNode->val < dat)
        {
            predecessor = currentNode;
            currentNode = currentNode->next;
        }

        if (predecessor == nullptr)
        {
            throw std::length_error("Predecessor not found: no element is less than the given value.");
        }

        return predecessor->val;
    }


    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        if (!Exists(dat))
        {
            // Predecessor restituisce un puntatore al nodo predecessore
            Node *prev = nullptr;
            Node *current = head;
            while (current != nullptr && current->val < dat)
            {
                prev = current;
                current = current->next;
            }
            // Creo nuovo nodo
            Node *newNode = new Node(dat);

            // Inserimento in testa
            if (prev == nullptr)
            {
                newNode->next = head;
                head = newNode;
                // Eventuale aggiornamento coda
                if (tail == nullptr)
                {
                    tail = newNode;
                }
            }
            else
            {
                // Inserimento in mezzo alla lista
                newNode->next = prev->next;
                prev->next = newNode;
                if (prev == tail)
                {
                    tail = newNode;
                }
            }

            size++;
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        if (!Exists(dat))
        {
            Node *prev = nullptr;
            Node *current = head;

            // Find the predecessor node
            while (current != nullptr && current->val < dat)
            {
                prev = current;
                current = current->next;
            }

            Node *newNode = new Node(std::move(dat));

            if (prev == nullptr)
            {
                newNode->next = head;
                head = newNode;
                if (tail == nullptr)
                {
                    tail = newNode;
                }
            }
            else
            {
                newNode->next = prev->next;
                prev->next = newNode;
                if (prev == tail)
                {
                    tail = newNode;
                }
            }

            size++;
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetLst<Data>::Remove(const Data &dat)
    {
        if (!Exists(dat))
        {
            return false;
        }

        Node *prev = nullptr;
        Node *current = head;

        // Find the predecessor node
        while (current != nullptr && current->val != dat)
        {
            prev = current;
            current = current->next;
        }

        Node *toDelete = current;

        if (prev == nullptr)
        {
            head = head->next;
            if (toDelete == tail)
            {
                tail = nullptr;
            }
        }
        else
        {
            prev->next = toDelete->next;
            if (toDelete == tail)
            {
                tail = prev;
            }
        }

        delete toDelete;
        --size;
        return true;
    }

    template <typename Data>
    const Data &SetLst<Data>::Successor(const Data &dat) const
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->val > dat)
            {
                return current->val;
            }
            current = current->next;
        }
        throw std::length_error("Successor not found");
    }

    template <typename Data>
    const Data SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        Node *current = head;
        Node *successor = nullptr;

        while (current != nullptr)
        {
            if (current->val > dat && (successor == nullptr || current->val < successor->val))
            {
                successor = current;
            }
            current = current->next;
        }

        if (successor == nullptr)
        {
            throw std::length_error("Successor not found: no element greater than the given value.");
        }

        const Data value = successor->val;
        Remove(successor->val);
        return value;
    }

    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->val > dat)
            {
                Remove(current->val);
                return;
            }
            current = current->next;
        }
        throw std::length_error("Successor not found: no element greater than the given value.");
    }

    template <typename Data>
    const Data SetLst<Data>::PredecessorNRemove(const Data &dat)
    {
        Node *predecessor = nullptr;
        Node *currentNode = head;

        while (currentNode != nullptr && currentNode->val < dat)
        {
            predecessor = currentNode;
            currentNode = currentNode->next;
        }

        if (predecessor == nullptr)
        {
            throw std::length_error("Predecessor not found: no element is less than the given value.");
        }

        const Data value = predecessor->val;
        Remove(predecessor->val);
        return value;
    }

    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }

        Node *currentNode = head;
        Node *predecessor = nullptr;

        while (currentNode != nullptr && currentNode->val < dat)
        {
            predecessor = currentNode;
            currentNode = currentNode->next;
        }

        if (predecessor == nullptr)
        {
            throw std::length_error("Predecessor not found: no element is less than the given value.");
        }

        Remove(predecessor->val);
    }

    template <typename Data>
    const Data SetLst<Data>::MinNRemove()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }
        else
        {
            const Data value = head->val;
            RemoveMin();
            return value;
        }
    }

    template <typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }
        else
        {
            Remove(head->val);
        }
    }

    template <typename Data>
    const Data SetLst<Data>::MaxNRemove()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }
        else
        {
            const Data value = tail->val;
            RemoveMax();
            return value;
        }
    }

    template <typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if (List<Data>::Empty())
        {
            throw std::length_error("The set is empty");
        }
        else
        {
            Remove(tail->val);
        }
    }

}
