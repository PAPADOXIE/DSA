#pragma once

class Queue
{
public:
    Queue();

    void enqueue();
    void dequeue();

private:
    int *customerID;
    int head;
    int tail;
    int counter;
};