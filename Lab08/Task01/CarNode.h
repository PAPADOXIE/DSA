#pragma once
#include <string>
#include <iostream>

class CarNode
{
public:
    CarNode();
    CarNode(std::string company,
            std::string brand,
            std::string transmission,
            int engineCapacity,
            int seatingCapacity,
            std::string registered,
            int mileage,
            int price,
            CarNode *next);

    void show();
    friend std::ostream &operator<<(std::ostream &out, CarNode *node);

    std::string company;
    std::string brand;
    std::string transmission;
    int engineCapacity;
    int seatingCapacity;
    std::string registered;
    int mileage;
    int price;
    CarNode *next;
    CarNode *prev;
};