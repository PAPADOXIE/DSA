#include <iostream>

int main()
{
    int N = 32;
    int i = 1;

    for (i - 1; i < N*2; i++)
    {
        for (int j = N; j >= 2; j /= 2)
        {
            if (i % j == 0)
            {
                std::cout << N / j << " ";
                break;
            }
        }
    }
}