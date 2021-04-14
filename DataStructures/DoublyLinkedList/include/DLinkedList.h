#include "Node.h"
#include <cstddef>
#include <iterator>

template <class T> class DLinkedList
{
  public:
    struct Iterator
    {
      public:
        // Tags for algorithms
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Node<T>;
        using pointer = Node<T> *;
        using reference = Node<T> &;

        //! Iterator Constructor
        Iterator(pointer ptr);

        //! Iterator operations
        reference operator*(pointer ptr) const;
        pointer operator->();
        // Increment Functions
        Iterator &operator++();
        Iterator operator++(int);
        // Decrement Functions
        Iterator operator--();
        Iterator operator--(int);
        // Equality Functions
        friend bool operator==(const Iterator &a, const Iterator &b);
        friend bool operator!=(const Iterator &a, const Iterator &b);

      private:
        // Pointer to the current element
        pointer node_ptr;
    };

    //! Class Constructor
    DLinkedList();

    //! Iterator Functions
    Iterator begin();         // Returns iterator pointing to the start of the list
    Iterator end();           // Returns iterator pointing to the end of the list
    Iterator rbegin();        // Returns iterator pointing to the end of the list
    Iterator rend();          // Returns iterator pointing to the start of the list
    const Iterator crbegin(); // Returns constant iterator pointing to the end of the list
    const Iterator crend();   // Returns constant iterator pointing to the start of the list

    //! Class Functions
    void add(T elem);   // Adds elements in order
    void add_s(T elem); // Adds element at the start of the list
    void add_t(T elem); // Adds element at the end of the list

    //! Class Destructor
    ~DLinkedList();

  private:
    Node<T> *head;
    Node<T> *tail;
};