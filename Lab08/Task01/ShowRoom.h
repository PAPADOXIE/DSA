#pragma once
#include "CarNode.h"
#include <string>
#include <iostream>

class ShowRoom
{
public:
    ShowRoom();

    CarNode *addCar();
    void addCar(std::string company,
                std::string brand,
                std::string transmission,
                int engineCapacity,
                int seatingCapacity,
                std::string registered,
                int mileage,
                int price,
                CarNode *next,
                CarNode *prev);

    void searchCompany(std::string company);
    void searchBrand(std::string brand);
    void searchManual();
    void searchAutomatic();
    void searchInPriceRange(int min, int max);

    friend std::ostream &operator<<(std::ostream &out, ShowRoom &showroom);

private:
    CarNode *head;
};