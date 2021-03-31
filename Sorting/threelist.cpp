#include <boost/container/container_fwd.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <fstream>
#include <boost/container/flat_map.hpp>

class ThreeList
{
  public:
    //! Constructors
    ThreeList()
    {
        m1.reserve(201000);
        m2.reserve(201000);
        m3.reserve(201000);
        maps.push_back(m1);
        maps.push_back(m2);
        maps.push_back(m3);
    }

    //! Functions
    void populateLists(int size, std::fstream &file)
    {
        int val1, val2, val3;
        for (int i = 0; i < size; i++)
        {
            //std::cin >> val1 >> val2 >> val3;
            file >> val1 >> val2 >> val3;
            maps.at(0).emplace(val1, val2);
            maps.at(1).emplace(val2, val3);
            maps.at(2).emplace(val3, val1);
        }
    }

    void solve(int listNumber, int indexNumber)
    {
        int iter = 0;

        auto i = maps.at(listNumber).nth(indexNumber);

        switch (listNumber)
        {
            case 0:
                std::cout << i->first << " " << i->second << " " << maps.at(1).at(i->second) << "\n";
                break;

            case 1:
                std::cout << maps.at(2).at(i->second) << " " << i->first << " " << i->second << "\n";
                break;

            case 2:
                std::cout << i->second << " " << maps.at(0).at(i->second) << " " << i->first << "\n";
                break;
        }


        // for (auto &i : maps.at(listNumber))
        // {
        //     if (iter == indexNumber)
        //     {
        //         switch (listNumber)
        //         {
        //         case 0:
        //             std::cout << i.first << " " << i.second << " " << maps.at(1).at(i.second) << "\n";
        //             break;

        //         case 1:
        //             std::cout << maps.at(2).at(i.second) << " " << i.first << " " << i.second << "\n";
        //             break;

        //         case 2:
        //             std::cout << i.second << " " << maps.at(0).at(i.second) << " " << i.first << "\n";
        //             break;
        //         }
        //         break;
        //     }

        //     iter++;
        // }
    }

    //! Destructor
    ~ThreeList()
    {
        maps.clear();
        m1.clear();
        m2.clear();
        m3.clear();
    }

  private:
    //! Mapped Lists
    //std::map<int, int> m1, m2, m3;
    //std::vector<std::map<int, int>> maps;

    boost::container::flat_map<int, int> m1, m2, m3;
    std::vector<boost::container::flat_map<int, int>> maps;

};

int main()
{
    std::fstream file;
    file.open("testfile.txt", std::ios::in);

    int size, inputs, listNumber, indexNumber;
    ThreeList solver;

    //std::cin >> size;
    file >> size;
    solver.populateLists(size, file);

    //std::cin >> inputs;
    file >> inputs;

    for (int i = 0; i < inputs; i++)
    {
        //std::cin >> listNumber >> indexNumber;
        file >> listNumber >> indexNumber;
        solver.solve(listNumber, indexNumber);

    }
    return 0;
}