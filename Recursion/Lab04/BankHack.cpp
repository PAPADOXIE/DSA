#include <iostream>

bool hackerman(int money, int goal)
{

    if (money == goal)
        return true;

    if (money > goal)
        return false;

    if (hackerman(money * 10, goal))
        return true;

    if (hackerman(money * 20, goal))
        return true;

    return false;
}

int main()
{
    int goal, runs;
    std::cin >> runs;

    for (int i = 0; i < runs; i++)
    {
        std::cin >> goal;
        if (hackerman(1, goal))
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
}