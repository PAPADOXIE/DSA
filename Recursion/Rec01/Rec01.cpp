#include <iostream>

void print(const int i, const int N)
{
    if (i >= N)
    {
        return;
    }

    print(i * 2, N);
    std::cout << i << '\n';
    print(i * 2, N);
}

int main()
{
    print(1, 32);
    return 0;
}