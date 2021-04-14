#include <iostream>

class CountWhite
{
  public:
    CountWhite(int n)
    {
        numWhite = 0;
        this->n = n;
        square = new char *[n];

        for (int i = 0; i < n; i++)
        {
            square[i] = new char[n];
        }
    }

    void populate()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < n; j++)
            {
                std::cin >> square[i][j];
            }
        }
    }

    void solve(int x, int y, int size)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                solve(x + i, y + j, size);
                if (size != 0)
                {
                    numWhite++;
                    std::cout << size << " ";
                }
                size = 0;
            }
        }
    }

    int numWhite;

  private:
    int n;
    char **square;

    bool solveHelper(int x, int y, int &size)
    {
        if (square[x][y] == 'b')
        {
            return false;
        }

        if (square[x][y] == 'w')
        {
            square[x][y] = 'b';
            size++;
        }

        if (x != n - 1)
        {
            solveHelper(x + 1, y, size);
        }

        if (y != n - 1)
        {
            solveHelper(x, y + 1, size);
        }

        return false;
    }
};

int main()
{
    int size = 0;
    int x = 0, y = 0;

    CountWhite cw(10);

    cw.populate();
    cw.solve(x, y, size);
    std::cout << "Number of white areas:" << cw.numWhite;
}