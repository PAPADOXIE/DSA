#include "../include/Node.h"

template <class T> Node<T>::Node()
{
    this->prev = nullptr;
    this->next = nullptr;
}

template <class T> Node<T>::Node(T data)
{
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

template <class T> Node<T>::Node(T data, T *prev, T *next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}