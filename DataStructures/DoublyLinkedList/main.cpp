#include "include/DLinkedList.h"
#include <iostream>

int main()
{
    DLinkedList<int> numList;

    numList.add(5);
    numList.add(8);
    numList.add(23);
    numList.add(1);
    numList.add(4);
    numList.add(7);

    for(auto it = numList.begin(); it != numList.end(); it++){
        std::cout << it->data << '\n';
    }

    return 0;
}