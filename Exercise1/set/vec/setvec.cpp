namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec() : vector(INIT_SIZE), head(0), tail(0)
    {
        size = INIT_SIZE;
    }

    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data> &con) : vector(con.Size())
    {
        size = con.Size();
        con.Traverse(
            [this](const Data &dat)
            {
                if (!Exists(dat))
                {
                    Insert(dat);
                }
            });
    }

    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data> &&con) noexcept : vector(con.Size())
    {
        size = con.Size();
        con.Map(
            [this](Data &dat)
            {
                if (!Exists(dat))
                {
                    Insert(std::move(dat));
                }
            });
    }

    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data> &con)
    {
        size = con.size;
        head = con.head;
        tail = con.tail;
        vector = con.vector;
    }

    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data> &&con)
    {
        std::swap(size, con.size);
        std::swap(head, con.head);
        std::swap(tail, con.tail);
        std::swap(vector, con.vector);
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &con)
    {
        if (this != &con)
        {
            size = con.size;
            head = con.head;
            tail = con.tail;
            vector = con.vector;
        }
        return *this;
    }

    template <typename Data>
    SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&con)
    {
        if (this != &con)
        {
            std::swap(size, con.size);
            std::swap(head, con.head);
            std::swap(tail, con.tail);
            std::swap(vector, con.vector);
        }
        return *this;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator==(const SetVec<Data> &con) const noexcept
    {
        if (Size() != con.Size())
        {
            return false;
        }
        for (ulong i = 0; i < Size(); ++i)
        {
            if (!con.Exists(vector[(head + i) % size]))
            {
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    inline bool SetVec<Data>::operator!=(const SetVec<Data> &con) const noexcept
    {
        return !(*this == con);
    }

    template <typename Data>
    const Data &SetVec<Data>::Min() const
    {
        
    }

    template <typename Data>
    const Data &SetVec<Data>::MinNRemove()
    {
        
    }

    template <typename Data>
    void SetVec<Data>::RemoveMin()
    {
        
    }

    template <typename Data>
    const Data &SetVec<Data>::Max() const
    {
        
    }

    template <typename Data>
    const Data &SetVec<Data>::MaxNRemove()
    {
        
    }

    template <typename Data>
    void SetVec<Data>::RemoveMax()
    {
        
    }

    template <typename Data>
    const Data &SetVec<Data>::Predecessor(const Data &data) const
    {
        
    }

    template <typename Data>
    const Data &SetVec<Data>::PredecessorNRemove(const Data &data)
    {
        
    }

    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data &data)
    {
  
    }

    template <typename Data>
    const Data &SetVec<Data>::Successor(const Data &data) const
    {
      
    }

    template <typename Data>
    const Data &SetVec<Data>::SuccessorNRemove(const Data &data)
    {
        
    }

    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data &data)
    {

    }

    template <typename Data>
    bool SetVec<Data>::Insert(const Data &data)
    {
        
    }

    template <typename Data>
    bool SetVec<Data>::Insert(Data &&data)
    {
        
    }

    template <typename Data>
    bool SetVec<Data>::Remove(const Data &data)
    {
      
    }

    template <typename Data>
    const Data &SetVec<Data>::operator[](ulong index) const
    {
        if (index >= Size())
        {
            throw std::out_of_range("Index out of range.");
        }
        return vector[(head + index) % size];
    }

    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        ulong index = head;
        while (index != tail)
        {
            if (vector[index] == data)
            {
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    template <typename Data>
    void SetVec<Data>::Clear()
    {
        head = 0;
        tail = 0;
        vector.Clear();
        size = INIT_SIZE;
    }

    template <typename Data>
    void SetVec<Data>::Resize(ulong newDim)
    {
        
    }

    template <typename Data>
    bool SetVec<Data>::Empty() const noexcept
    {
        return (tail == head);
    }

    template <typename Data>
    inline ulong SetVec<Data>::Size() const noexcept{
      if (Empty()) {
        return 0;
      } else if (tail >= head) {
        return tail - head;
      } else {
        return vector.size() - head + tail;
      }
    }
    
    template <typename Data>
    ulong SetVec<Data>::BinarySearchIndex(const Data& data) const {
      ulong left = 0;
      ulong right = Size();
      ulong capacity = vector.size(); 

      while (left < right) {
        ulong mid = left + (right - left) / 2;
        ulong midindex = (head + mid) % capacity;

        if (vector[midindex] < data) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return (head + left) % capacity;
    }

}
