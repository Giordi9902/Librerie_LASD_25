
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
        std::swap(head,con.head);
        std::swap(tail,con.tail);
        std::swap(size,con.size);
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(const SetLst<Data> &con)
    {
        Clear();
        con.Traverse(
            ([this](const Data &dat)
             {
                if (!Exists(dat))
                    Insert(dat); }));
        return *this;
    }

    template <typename Data>
    SetLst<Data> &SetLst<Data>::operator=(SetLst<Data> &&con) noexcept
    {
        Clear();
        std::swap(head,con.head);
        std::swap(tail,con.tail);
        std::swap(size,con.size);
        return *this;
    }

    template <typename Data>
    bool SetLst<Data>::operator==(const SetLst<Data> &con) const noexcept
    {
        if (size != con.size)
        {
            return false;
        }
        typename List<Data>::Node* current1 = head;
        typename List<Data>::Node* current2 = con.head;
        while (current1 != nullptr) {
            if (current1->val != current2->val) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
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
        const Data& minValue = Min();
        RemoveMin();
        return minValue;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMin()
    {
        if (size == 0 || head == nullptr) {
            throw std::length_error("SetLst is empty.");
        }
        typename List<Data>::Node* temp = head;
        head = head->next;
        delete temp;
        --size;
        if (size == 0) {
            tail = nullptr;
        }
    }

    template <typename Data>
    const Data &SetLst<Data>::Max() const
    {
        if (size == 0) {
            throw std::length_error("SetLst is empty.");
        }
        return tail->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::MaxNRemove()
    {
        const Data& maxValue = Max();
        RemoveMax();
        return maxValue;
    }

    template <typename Data>
    void SetLst<Data>::RemoveMax()
    {
        if (size == 0) {
            throw std::length_error("SetLst is empty.");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            typename List<Data>::Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        --size;
    }

    template <typename Data>
    const Data &SetLst<Data>::Predecessor(const Data &dat) const
    {
        if (size == 0 || head->val >= dat) {
            throw std::out_of_range("No predecessor exists.");
        }
        typename List<Data>::Node* current = head;
        typename List<Data>::Node* prev = nullptr;
        while (current != nullptr && current->val < dat) {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr) {
            throw std::out_of_range("No predecessor exists.");
        }
        return prev->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::PredecessorNRemove(const Data &dat)
    {
        const Data& predValue = Predecessor(dat);
        Remove(predValue);
        return predValue;
    }

    template <typename Data>
    void SetLst<Data>::RemovePredecessor(const Data &dat)
    {
        const Data& predValue = Predecessor(dat);
        Remove(predValue);
    }

    template <typename Data>
    const Data &SetLst<Data>::Successor(const Data &dat) const
    {
        typename List<Data>::Node* current = head;
        while (current != nullptr && current->val <= dat) {
            current = current->next;
        }
        if (current == nullptr) {
            throw std::out_of_range("No successor exists.");
        }
        return current->val;
    }

    template <typename Data>
    const Data &SetLst<Data>::SuccessorNRemove(const Data &dat)
    {
        const Data& succValue = Successor(dat);
        Remove(succValue);
        return succValue;
    }

    template <typename Data>
    void SetLst<Data>::RemoveSuccessor(const Data &dat)
    {
        const Data& succValue = Successor(dat);
        Remove(succValue);
    }

    template <typename Data>
    bool SetLst<Data>::Insert(const Data &dat)
    {
        if (Exists(dat)) {
            return false;
        }
        InsertInOrder(dat);
        return true;
    }

    template <typename Data>
    bool SetLst<Data>::Insert(Data &&dat)
    {
        if (Exists(dat)) {
            return false;
        }
        InsertInOrder(std::move(dat));
        return true;
    }

    template <typename Data>
    bool SetLst<Data>::Remove(const Data &dat)
    {
        typename List<Data>::Node* current = head;
        typename List<Data>::Node* prev = nullptr;
        while (current != nullptr) {
            if (current->val == dat) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                --size;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    template <typename Data>
    const Data &SetLst<Data>::operator[](ulong idx) const
    {
        if (idx >= size) {
            throw std::out_of_range("Index out of range.");
        }
        typename List<Data>::Node* current = head;
        for (ulong i = 0; i < idx; ++i) {
            current = current->next;
        }
        return current->val;
    }

    template <typename Data>
    void SetLst<Data>::InsertInOrder(const Data &dat)
    {
        typename List<Data>::Node* newNode = nullptr;
        try {
            newNode = new typename List<Data>::Node(dat);
        } catch (...) {
            throw std::bad_alloc();
        }
        if (head == nullptr || head->val >= dat) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = head;
            }
        } else {
            typename List<Data>::Node* current = head;
            while (current->next != nullptr && current->next->val < dat) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        ++size;
    }

    template <typename Data>
    void SetLst<Data>::InsertInOrder(Data &&dat)
    {
        typename List<Data>::Node* newNode = new typename List<Data>::Node(std::move(dat));
        if (head == nullptr || head->val >= dat) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = head;
            }
        } else {
            typename List<Data>::Node* current = head;
            while (current->next != nullptr && current->next->val < dat) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        ++size;
    }
}
