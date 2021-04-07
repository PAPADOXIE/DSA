#include "../include/DLinkedList.h"
#include <string>
#include <vector>

#define TEMP template <class T>
#define ITER typename DLinkedList<T>::Iterator // Used where I want to return an Iterator

TEMP using value_type = Node<T>;  // Used where I want to return a Node
TEMP using pointer = Node<T> *;   // Used where I want to return a pointer to a Node
TEMP using reference = Node<T> &; // Used where I want to return a reference to a Node

//! Iterator Constructor
TEMP DLinkedList<T>::Iterator::Iterator(pointer ptr)
{
    node_ptr = ptr;
}

//! Iterator Operators
TEMP reference<T> DLinkedList<T>::Iterator::operator*(pointer ptr) const
{
    return *node_ptr;
}

TEMP pointer<T> DLinkedList<T>::Iterator::operator->()
{
    return node_ptr;
}

TEMP ITER &DLinkedList<T>::Iterator::operator++()
{
    node_ptr = node_ptr->next;
    return *this;
}

TEMP ITER DLinkedList<T>::Iterator::operator++(int)
{
    ITER temp = *this;
    (*this)++;
    return temp;
}

TEMP ITER DLinkedList<T>::Iterator::operator--()
{
    node_ptr = node_ptr->prev;
    return *this;
}

TEMP ITER DLinkedList<T>::Iterator::operator--(int)
{
    ITER temp = *this;
    (*this)--;
    return temp;
}

TEMP bool operator==(const ITER &a, const ITER &b)
{
    return a.node_ptr == b.node_ptr;
}

TEMP bool operator!=(const ITER &a, const ITER &b)
{
    return a.node_ptr != b.node_ptr;
}

//! Class Constructor
TEMP DLinkedList<T>::DLinkedList()
{
    // Dummy nodes
    head = new Node<T>();
    tail = new Node<T>();

    head->next = tail;
    head->prev = nullptr;
    tail->next = nullptr;
    tail->prev = head;
}

//! Iterator Functions
TEMP ITER DLinkedList<T>::begin()
{
    return Iterator(head->next);
}

TEMP ITER DLinkedList<T>::end()
{
    return Iterator(tail);
}

TEMP ITER DLinkedList<T>::rbegin()
{
    return Iterator(head->prev);
}

TEMP ITER DLinkedList<T>::rend()
{
    return Iterator(head->next);
}

TEMP const ITER DLinkedList<T>::crbegin()
{
    return Iterator(head->prev);
}

TEMP const ITER DLinkedList<T>::crend()
{
    return Iterator(head->next);
}

//! Class Functions
TEMP void DLinkedList<T>::add(T elem)
{
    Node<T> *newNode = new Node<T>(elem);

    for (auto it = this->begin(); it != this->end(); it++)
    {
        if (it->data > elem)
        {
            newNode->next = it;
            newNode->prev = it->prev;
            it->prev->next = newNode;
            it->prev = newNode;
        }
    }
}

//! Class Destructor
TEMP DLinkedList<T>::~DLinkedList()
{
    for (auto it = this->begin(); it != this->end();)
    {
        auto temp_itr = it->next;
        delete it;
        it = temp_itr;
    }
    delete head;
    delete tail;
}

template class DLinkedList<int>;
template class DLinkedList<std::string>;
template class DLinkedList<int *>;
template class DLinkedList<char *>;
template class DLinkedList<char>;