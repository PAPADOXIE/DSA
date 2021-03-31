#include <iostream>

int count7(int val)
{
    if (val % 10 == val)
    {
        if (val == 7)
        {
            return 1;
        }
        return 0;
    }
    if (val % 10 == 7)
    {
        return 1 + count7(val / 10);
    }
    return count7(val / 10);
}

int main()
{
    int val;
    std::cin >> val;
    std::cout << count7(val);
    return 0;
}