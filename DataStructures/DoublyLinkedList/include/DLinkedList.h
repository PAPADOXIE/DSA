#include "Node.h"
#include <cstddef>
#include <iterator>

template <class T> class DLinkedList
{
  public:

    struct Iterator
    {
      public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        //Iterator Constructor
        Iterator(pointer ptr);
        
        //Iterator operations
        reference operator *(pointer ptr) const;
        pointer operator ->();
        Iterator &operator ++();
        Iterator operator ++(int);
        friend bool operator ==(const Iterator &a, const Iterator &b);
        friend bool operator !=(const Iterator &a, const Iterator &b);

      private:
        //Pointer to the current element
        pointer m_ptr;
    };

    //Constructor
    DLinkedList();

    //Iterator functions
    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();
    Iterator crbegin() const;
    Iterator crend() const;

    ~DLinkedList();

  private:
    Node<T> *head;
    Node<T> *tail;
};