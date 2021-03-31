#include <iostream>

class Maze
{
  public:
    Maze(int M, int N)
    {
        rows = M;
        columns = N;
        maze = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            maze[i] = new int[columns];
        }
    }

    void populate()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cin >> maze[i][j];
            }
        }
    }

    bool solve(int row, int column)
    {
        if (maze[row][column] == 2)
        {
            return true;
        }

        if (maze[row][column] == 0)
        {
            return false;
        }

        maze[row][column] = 0;

        if (row != rows - 1)
        {
            if (solve(row + 1, column))
                return true;
        }

        if (column != columns - 1)
        {
            if (solve(row, column + 1))
                return true;
        }

        if (column != 0)
        {
            if (solve(row, column - 1))
                return true;
        }

        if (row != 0)
        {
            if (solve(row - 1, column))
                return true;
        }

        return false;
    }

  private:
    int rows, columns;
    int **maze;
};

int main()
{
    int M, N;
    std::cin >> M >> N;

    Maze maze(M, N);
    maze.populate();

    if (maze.solve(0, 0))
    {
        std::cout << "Path Found\n";
    }
    else
    {
        std::cout << "Path Not Found\n";
    }

    return 0;
}
