#pragma once

template <class T> class Node
{
  public:
    
    //!Constructors
    Node();
    Node(T data);
    Node(T data, T *prev, T *next);

    //!Variables
    Node<T> *next;
    Node<T> *prev;
    T data;
};