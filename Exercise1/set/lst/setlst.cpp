
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
                    Insert(dat);
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
                    Insert(std::move(dat));
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
                    Insert(dat);
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
                    Insert(std::move(dat));
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
                {
                    Insert(dat);
                } }));
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
                    Insert(std::move(dat));
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
                {
                    isEqual = false;
                    throw std::runtime_error("Mismatch found");
                } }));
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
        typename List<Data>::Node *minNode = head;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val < minNode->val)
            {
                minNode = current;
            }
            current = current->next;
        }
        return minNode->val;
    }

    template <typename Data>
    const Data& SetLst<Data>::MinNRemove()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        Data& min = head->val;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val < min)
            {
                min = current->val;
            }
            current = current->next;
        }
        Remove(min);
        return min;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        Data min = head->val;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val < min)
            {
                min = current->val;
            }
            current = current->next;
        }
        Remove(min);
    }

    template <typename Data>
    const Data &SetLst<Data>::Max() const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *maxNode = head;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val > maxNode->val)
            {
                maxNode = current;
            }
            current = current->next;
        }
        return maxNode->val;
    }

    template <typename Data>
    const Data& SetLst<Data>::MaxNRemove()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        Data& max = head->val;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val > max)
            {
                max = current->val;
            }
            current = current->next;
        }
        Remove(max);
        return max;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        Data max = head->val;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val > max)
            {
                max = current->val;
            }
            current = current->next;
        }
        Remove(max);
    }

    template <typename Data>
    const Data &SetLst<Data>::Predecessor(const Data &dat) const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *predNode = nullptr;
        typename List<Data>::Node *current = head;
        while (current != nullptr)
        {
            if (current->val < dat && (predNode == nullptr || current->val > predNode->val))
            {
                predNode = current;
            }
            current = current->next;
        }
        if (predNode == nullptr)
        {
            throw std::out_of_range("Error: no predecessor found");
        }
        return predNode->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::PredecessorNRemove(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *predNode = nullptr;
        typename List<Data>::Node *current = head;
        while (current != nullptr)
        {
            if (current->val < dat && (predNode == nullptr || current->val > predNode->val))
            {
                predNode = current;
            }
            current = current->next;
        }
        if (predNode == nullptr)
        {
            throw std::out_of_range("Error: no predecessor found");
        }
        Data &pred = predNode->val;
        Remove(pred);
        return pred;
    }

    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        Data pred = head->val;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val < dat && current->val > pred)
            {
                pred = current->val;
            }
            current = current->next;
        }
        Remove(pred);
    }

    template <typename Data>
    const Data &SetLst<Data>::Successor(const Data &dat) const
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *succNode = nullptr;
        typename List<Data>::Node *current = head;
        while (current != nullptr)
        {
            if (current->val > dat && (succNode == nullptr || current->val < succNode->val))
            {
                succNode = current;
            }
            current = current->next;
        }
        if (succNode == nullptr)
        {
            throw std::out_of_range("Error: no successor found");
        }
        return succNode->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        typename List<Data>::Node *succNode = nullptr;
        typename List<Data>::Node *current = head;
        while (current != nullptr)
        {
            if (current->val > dat && (succNode == nullptr || current->val < succNode->val))
            {
                succNode = current;
            }
            current = current->next;
        }
        if (succNode == nullptr)
        {
            throw std::out_of_range("Error: no successor found");
        }
        Data &succ = succNode->val;
        Remove(succ);
        return succ;
    }

    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        if (size == 0)
        {
            throw std::length_error("Error: the set is empty");
        }
        Data succ = head->val;
        typename List<Data>::Node *current = head->next;
        while (current != nullptr)
        {
            if (current->val > dat && current->val < succ)
            {
                succ = current->val;
            }
            current = current->next;
        }
        Remove(succ);
    }

    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        if (!Exists(dat))
        {
            List<Data>::InsertAtBack(dat);
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        if (!Exists(dat))
        {
            List<Data>::InsertAtBack(std::move(dat));
            return true;
        }
        return false;
    }

    template <typename Data>
    bool SetLst<Data>::Remove(const Data &dat)
    {
        if (Exists(dat))
        {
            typename List<Data>::Node *current = head;
            typename List<Data>::Node *previous = nullptr;

            while (current != nullptr)
            {
                if (current->val == dat)
                {
                    if (previous == nullptr)
                    {
                        head = current->next;
                    }
                    else
                    {
                        previous->next = current->next;
                    }
                    delete current;
                    --size;
                    return true;
                }
                previous = current;
                current = current->next;
            }
            return false;
            return true;
        }
        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::operator[](unsigned long idx) const
    {
        if (idx >= size)
        {
            throw std::out_of_range("Error: index out of range");
        }
        return List<Data>::operator[](idx);
    }
}
