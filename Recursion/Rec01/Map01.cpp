#include <iostream>
#include <map>
#include <stdexcept>

int main()
{
    int N = 32;
    int i = 1;
    std::map<int, int> vals;

    for (int j = N / 2, k = 1; j > 0; j /= 2, k *= 2)
    {
        vals.emplace(k, j);
    }

    for(auto &i : vals){
        std::cout << i.first << " ";
        std::cout << i.second << "\n";
    }

    for (i - 1; i < N; i++)
    {
        try
        {
            std::cout << vals.at(i) << " ";
        }
        catch (std::out_of_range){}
    }
}