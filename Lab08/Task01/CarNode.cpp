#include "CarNode.h"
#include <cstdio>

CarNode::CarNode()
{
    this->company = "";
    this->brand = "";
    this->transmission = "";
    this->engineCapacity = 0;
    this->seatingCapacity = 0;
    this->registered = "";
    this->mileage = 0;
    this->price = 0;
    this->next = nullptr;
    this->prev = nullptr;
}

CarNode::CarNode(std::string company,
                 std::string brand,
                 std::string registered,
                 int mileage,
                 int price,
                 std::string transmission = "Automatic",
                 int engineCapacity = 660,
                 int seatingCapacity = 4,
                 CarNode *next = nullptr)
{
    this->company = company;
    this->brand = brand;
    this->transmission = transmission;
    this->engineCapacity = engineCapacity;
    this->seatingCapacity = seatingCapacity;
    this->registered = registered;
    this->mileage = mileage;
    this->price = price;
    this->next = nullptr;
    this->prev = nullptr;
}

void CarNode::show()
{
    printf("%s\t%s\t%s\t%d\t%d\t%s\t%d\t%d\t",
           company,
           brand,
           transmission,
           engineCapacity,
           seatingCapacity,
           registered,
           mileage,
           price);
}

std::ostream &operator<<(std::ostream &out, CarNode *node)
{
    out << node->company << " "
        << node->brand << " "
        << node->engineCapacity << " CC "
        << "[Rs. " << node->price << " only]\n"
        << node->transmission << " "
        << node->registered << "\n"
        << "Seating Capacity: " << node->seatingCapacity << "\n"
        << "Mileage: " << node->mileage << "\n";

    return out;
}