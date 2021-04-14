#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T> class Stack
{
    T *x;
    int p, size;

  public:
    Stack(int s = 10)
    {
        size = s;
        x = new T[size];
        p = 0;
    }
    bool isFull()
    {
        return p == size;
    }
    bool isEmpty()
    {
        return p == 0;
    }
    void push(T d)
    {
        if (isFull())
            throw(size);
        x[p++] = d;
    }
    T pop()
    {
        if (isEmpty())
            throw(0);
        return x[--p];
    }
    T seeTop()
    {
        if (isEmpty())
            throw(0);
        return x[p - 1];
    }
    ~Stack()
    {
        delete[] x;
    }
};

void printReversedLists(int *arr, int size)
{
    Stack<int> listStack(size);
    int data = -1;

    for (int i = 0; i < size; i++)
    {
        listStack.push(arr[i]);
    }

    while (!listStack.isEmpty())
    {
        try
        {
            data = listStack.pop();
        }
        catch (int err)
        {
            std::cout << "Error\n";
            continue;
        }

        if (data == -1)
        {
            std::cout << '\n';
            continue;
        }
        std::cout << data << " ";
    }
}

void printDivisors(int num)
{
    Stack<int> div;
    div.push(num);
    int i;
    bool last = false;

    while (!div.isEmpty())
    {
        num = div.pop();
        for (i = 2; i < num / 2; i++)
        {
            last = false;
            if (num % i == 0)
            {
                break;
            }
            last = true;
        }

        if (last == true)
        {
            return;
        }

        if ((i * i) == num)
        {
            std::cout << "Divisor of " << num << ": " << i << '\n';
            break;
        }

        std::cout << "Divisor of " << num << ": " << i << ", " << num / i << '\n';
        div.push(num / i);
    }
}

void checkCorrectness()
{
    Stack<char> charStack(255);
    char expression[255];
    // strncpy(expression, "[x+{(y+z)*(y-x)+(x+y(2*z))}]", 255);
    strncpy(expression, "{(y+z)*(y-x)]", 255);

    for (int i = 0; i < 255; i++)
    {
        if (expression[i] == '\0')
        {
            break;
        }
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            charStack.push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            try
            {
                char bracket = charStack.pop();
                if ((expression[i] == ')' && bracket == '(') || (expression[i] == '}' && bracket == '{') ||
                    (expression[i] == ']' && bracket == '['))
                {
                    continue;
                }
                else
                {
                    throw(0);
                }
            }
            catch (int ex)
            {
                std::cout << expression << " is incorrect expression\n";
                return;
            }
        }
    }

    if (!charStack.isEmpty())
    {
        std::cout << expression << " is incorrect expression\n";
        return;
    }

    std::cout << expression << " is correct expression\n";
}

void divideAdditively(int num)
{
    Stack<int> division(num);
    std::vector<int> previous;

    division.push(num);
    bool end = false;

    while (!division.isEmpty())
    {
        num = division.pop();

        if (num == 0 || num == 1)
        {
            continue;
        }

        auto it = std::find(previous.begin(), previous.end(), num);

        if (it != previous.end())
        {
            continue;
        }

        if (floor(num / 2) * 2 == num)
        {
            previous.push_back(num);
            std::cout << num << ": " << num / 2 << " + " << num / 2 << '\n';
            division.push(num / 2);
            continue;
        }

        std::cout << num << ": " << floor(num / 2) + 1 << "+" << floor(num / 2) << '\n';
        division.push(floor(num / 2));
        division.push(floor(num / 2) + 1);
        previous.push_back(num);
    }
}

int main()
{
    int arr[] = {-1, 4, 5, 7, 6, -1, 5, 5, 9, -1};
    printReversedLists(arr, 10);
    checkCorrectness();
    printDivisors(49);
	divideAdditively(32);

    return 0;
}
