
namespace lasd
{

    // __/\\\\\_____/\\\_______________________/\\\_________________
    //  _\/\\\\\\___\/\\\______________________\/\\\_________________
    //   _\/\\\/\\\__\/\\\______________________\/\\\_________________
    //    _\/\\\//\\\_\/\\\_____/\\\\\___________\/\\\______/\\\\\\\\__
    //     _\/\\\\//\\\\/\\\___/\\\///\\\____/\\\\\\\\\____/\\\/////\\\_
    //      _\/\\\_\//\\\/\\\__/\\\__\//\\\__/\\\////\\\___/\\\\\\\\\\\__
    //       _\/\\\__\//\\\\\\_\//\\\__/\\\__\/\\\__\/\\\__\//\\///////___
    //        _\/\\\___\//\\\\\__\///\\\\\/___\//\\\\\\\/\\__\//\\\\\\\\\\_
    //         _\///_____\/////_____\/////______\///////\//____\//////////__

    template <typename Data>
    List<Data>::Node::Node(const Data &d) : val{d} {}

    template <typename Data>
    List<Data>::Node::Node(Data &&d) noexcept
    {
        std::swap(d, val);
    }

    template <typename Data>
    List<Data>::Node::Node(const Node &other) : val(other.val) {}

    template <typename Data>
    List<Data>::Node::Node(Node &&other) noexcept
    {
        std::swap(other.val, val);
        std::swap(other.next, next);
    }

    template <typename Data>
    List<Data>::Node::~Node()
    {
        delete next;
    }

    template <typename Data>
    bool List<Data>::Node::operator==(const Node &other) const noexcept
    {
        return val == other.val;
    }

    template <typename Data>
    bool List<Data>::Node::operator!=(const Node &other) const noexcept
    {
        return !((*this) == other);
    }

    // __/\\\______________________________________________
    //  _\/\\\______________________________________________
    //   _\/\\\______________/\\\__________________/\\\______
    //    _\/\\\_____________\///___/\\\\\\\\\\__/\\\\\\\\\\\_
    //     _\/\\\______________/\\\_\/\\\//////__\////\\\////__
    //      _\/\\\_____________\/\\\_\/\\\\\\\\\\____\/\\\______
    //       _\/\\\_____________\/\\\_\////////\\\____\/\\\_/\\__
    //        _\/\\\\\\\\\\\\\\\_\/\\\__/\\\\\\\\\\____\//\\\\\___
    //         _\///////////////__\///__\//////////______\/////____

    template <typename Data>
    List<Data>::List(const TraversableContainer<Data> &con)
    {
        con.Traverse([this](const Data &currData)
                     { InsertAtBack(currData); });
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data> &&con)
    {
        con.Map([this](Data &currData)
                { InsertAtBack(std::move(currData)); });
    }

    template <typename Data>
    List<Data>::List(const List<Data> &l)
    {
        size = l.size;
        if (size == 0)
            return;

        head = new Node(*(l.head));
        tail = head;

        Node *temp = l.head->next;

        while (temp)
        {
            tail->next = new Node(*temp);
            tail = tail->next;
            temp = temp->next;
        }
    }

    template <typename Data>
    List<Data>::List(List &&l)
    {
        std::swap(size, l.size);
        std::swap(head, l.head);
        std::swap(tail, l.tail);
    }

    template <typename Data>
    List<Data>::~List()
    {
        delete head;
        head = tail = nullptr;
        size = 0;
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(List<Data> &&l) noexcept
    {
        std::swap(size, l.size);
        std::swap(head, l.head);
        std::swap(tail, l.tail);
        return *this;
    }

    template <typename Data>
    bool List<Data>::operator==(const List<Data> &l) const noexcept
    {
        if (size != l.size)
            return false;

        Node *temp = head, *temp2 = l.head;

        while (temp != nullptr)
        {
            if (temp->val != temp2->val)
                return false;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }

    template <typename Data>
    bool List<Data>::operator!=(const List<Data> &l) const noexcept
    {
        return !(*this == l);
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(const List<Data> &con)
    {
        if (*this != con)
        {
            Clear();
            Node *current = con.head;
            while (current != nullptr)
            {
                InsertAtBack(current->val);
                current = current->next;
            }
        }
        return *this;
    }

    template <typename Data>
    const Data &List<Data>::operator[](const ulong ind) const
    {
        if (head == nullptr || ind >= size)
            throw std::out_of_range("List does not have enough elements");

        Node *temp = head;
        for (uint i = 0; i < ind; i++)
            temp = temp->next;
        return temp->val;
    }

    template <typename Data>
    Data &List<Data>::operator[](const ulong ind)
    {
        if (head == nullptr || ind >= size)
            throw std::out_of_range("List does not have enough elements");

        Node *temp = head;
        for (uint i = 0; i < ind; ++i)
            temp = temp->next;
        return temp->val;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        if (tail == nullptr)
            tail = head;
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data &&d)
    {
        Node *temp = new Node(std::move(d));
        temp->next = head;
        head = temp;
        if (tail == nullptr)
            tail = head;
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront()
    {
        if (!size)
            throw std::length_error("Cannot remove from Empty list");
        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        temp->next = nullptr;
        delete temp;
        --size;
    }

    template <typename Data>
    Data List<Data>::FrontNRemove()
    {
        if (!size)
            throw std::length_error("Cannot remove from Empty list");
        Data front = head->val;
        RemoveFromFront();
        return front;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data &d)
    {
        Node *temp = new Node(d);
        if (tail)
        {
            tail->next = temp;
        }
        else
        {
            head = temp;
        }
        tail = temp;
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data &&d)
    {
        Node *temp = new Node(std::move(d));
        if (tail)
        {
            tail->next = temp;
        }
        else
        {
            head = temp;
        }
        tail = temp;
        ++size;
    }

    template <typename Data>
    void List<Data>::RemoveFromBack()
    {
        if (!size)
            throw std::length_error("Cannot remove from Empty list");
        if (size == 1)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = FindPenultimateNode();
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        --size;
    }

    template <typename Data>
    Data List<Data>::BackNRemove()
    {
        if (!size)
            throw std::length_error("Cannot remove from Empty list");
        Data ret = tail->val;
        RemoveFromBack();
        return ret;
    }

    template <typename Data>
    const Data &List<Data>::Front() const
    {
        if (size)
            return head->val;
        throw std::length_error("Empty List");
    }
    template <typename Data>
    Data &List<Data>::Front()
    {
        if (size)
            return head->val;
        throw std::length_error("Empty List");
    }

    template <typename Data>
    const Data &List<Data>::Back() const
    {
        if (size)
            return tail->val;
        throw std::length_error("Empty List");
    }

    template <typename Data>
    Data &List<Data>::Back()
    {
        if (size)
            return tail->val;
        throw std::length_error("Empty List");
    }

    template <typename Data>
    void List<Data>::Clear()
    {
        delete head;
        head = tail = nullptr;
        size = 0;
    }

    template <typename Data>
    void List<Data>::Traverse(const TraverseFun fun) const
    {
        PreOrderTraverse(fun);
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(const TraverseFun fun) const
    {
        PreOrderTraverse(fun, head);
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(const TraverseFun fun) const
    {
        PostOrderTraverse(fun, head);
    }

    template <typename Data>
    void List<Data>::Map(const MapFun fun)
    {
        PreOrderMap(fun);
    }

    template <typename Data>
    void List<Data>::PreOrderMap(const MapFun fun)
    {
        PreOrderMap(fun, head);
    }

    template <typename Data>
    void List<Data>::PostOrderMap(const MapFun fun)
    {
        PostOrderMap(fun, head);
    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(const TraverseFun fun, Node *curr) const
    {
        while (curr)
        {
            fun(curr->val);
            curr = curr->next;
        }
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(const TraverseFun fun, Node *curr) const
    {
        if (!curr)
            return;
        PostOrderTraverse(fun, curr->next);
        fun(curr->val);
    }

    template <typename Data>
    void List<Data>::PreOrderMap(const MapFun fun, Node *curr)
    {
        while (curr)
        {
            fun(curr->val);
            curr = curr->next;
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(const MapFun fun, Node *curr)
    {
        if (!curr)
            return;
        PostOrderMap(fun, curr->next);
        fun(curr->val);
    }

    template <typename Data>
    typename List<Data>::Node* List<Data>::FindPenultimateNode() const {
        if (size <= 1) return nullptr;
        Node* temp = head;
        if(head == tail) return nullptr;
        while (temp->next != tail) {
            temp = temp->next;
        }
        return temp;
    }

}
