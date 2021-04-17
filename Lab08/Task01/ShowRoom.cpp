#include "ShowRoom.h"

ShowRoom::ShowRoom()
{
    head = new CarNode();
}

CarNode *ShowRoom::addCar()
{
    if (head->next == nullptr)
    {
        head->next = new CarNode();
        head->next->prev = head;
        return head->next;
    }

    CarNode *i = head->next;

    while (!(i->next == nullptr))
    {
        i = i->next;
    }

    i->next = new CarNode();
    i->next->prev = i;
    return i->next;
}

void ShowRoom::addCar(std::string company,
                      std::string brand,
                      std::string transmission,
                      int engineCapacity,
                      int seatingCapacity,
                      std::string registered,
                      int mileage,
                      int price,
                      CarNode *next = nullptr,
                      CarNode *prev = nullptr)
{
    CarNode *newnode = addCar();
    newnode->company = company;
    newnode->brand = brand;
    newnode->transmission = transmission;
    newnode->engineCapacity = engineCapacity;
    newnode->seatingCapacity = seatingCapacity;
    newnode->registered = registered;
    newnode->mileage = mileage;
    newnode->price = price;
}

void ShowRoom::searchCompany(std::string company)
{
    CarNode *i = head->next;

    while (!(i == nullptr))
    {
        if(i->company == company){
            std::cout << i << "\n";
        }
        i = i->next;
    }
}

void ShowRoom::searchBrand(std::string brand)
{
    CarNode *i = head->next;

    while (!(i == nullptr))
    {
        if(i->brand == brand){
            std::cout << i << "\n";
        }
        i = i->next;
    }
}

void ShowRoom::searchManual()
{
    CarNode *i = head->next;

    while (!(i == nullptr))
    {
        if(i->transmission == "Manual"){
            std::cout << i << "\n";
        }
        i = i->next;
    }
}

void ShowRoom::searchAutomatic()
{
    CarNode *i = head->next;

    while (!(i == nullptr))
    {
        if(i->transmission == "Automatic"){
            std::cout << i << "\n";
        }
        i = i->next;
    }
}

void ShowRoom::searchInPriceRange(int min, int max)
{
    CarNode *i = head->next;

    while (!(i == nullptr))
    {
        if(i->price >= min && i->price <= max){
            std::cout << i << "\n";
        }
        i = i->next;
    }
}

std::ostream &operator<<(std::ostream &out, ShowRoom &showroom)
{
    CarNode *i = showroom.head->next;

    while(!(i == nullptr))
    {
        out << i << "\n";
        i = i->next;
    }
    return out;
}