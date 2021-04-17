#include "Queue.h"
#include <iostream>
#include <random>

int main()
{
    srand(time(0));
    int irand = rand()%5;
    Queue barberShop;

    while(!(irand == 4))
    {
        switch(irand)
        {
            case 3:
                barberShop.dequeue();
                break;
            default:
                barberShop.enqueue();
        }

        irand = rand()%5;
    }

    for(int i = 0; i < 4; i++)
    {
        barberShop.dequeue();
    }

    return 0;
}