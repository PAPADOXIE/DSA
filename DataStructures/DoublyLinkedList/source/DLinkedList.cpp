#include "../include/DLinkedList.h"
#define TEMP template <class T>
#define TEMP_ITER template <class T> DLinkedList<T>::Iterator


//Iterator Constructor
TEMP DLinkedList<T>::Iterator::Iterator(pointer ptr)
{
    m_ptr = ptr;
}

TEMP_ITER::reference operator *(T *ptr) const{

}


TEMP DLinkedList<T>::DLinkedList()
{
}

TEMP DLinkedList<T>::~DLinkedList()
{
}