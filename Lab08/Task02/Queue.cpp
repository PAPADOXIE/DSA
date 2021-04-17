#include "Queue.h"
#include <iostream>

Queue::Queue()
{
    customerID = new int[4];
    head = 0;
    tail = 0;
    customerID[head] = 0;
    counter = 0;
}

void Queue::enqueue()
{
    counter++;
    std::cout << "Customer " << counter << " entered, ";

    if (customerID[head] == 0)
    {   
        customerID[head] = counter;
        std::cout << "Accepted\n";
        return;
    }
    
    if ((tail + 1) % 4 == head)
    {
        std::cout << "Refused\n";
        return;
    }

    tail = (tail + 1) % 4;
    customerID[tail] = counter;
    std::cout << "Accepted\n";
}

void Queue::dequeue()
{
    if(customerID[head] == 0)
    {
        return;
    }

    std::cout << "Customer " << customerID[head] << " served\n";

    if(head == tail)
    {
        customerID[head] = 0;
        return;
    }

    head = (head+1)%4;
    std::cout << "Customer " << customerID[head] << " assigned cutting chair\n";
}