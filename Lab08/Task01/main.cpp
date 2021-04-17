#include "ShowRoom.h"
#include <string>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define FRED(x) KRED x RST
#define BOLD(x) "\x1B[1m" x RST

int main()
{
    ShowRoom ButtMotors;

    ButtMotors.addCar("Honda", 
                      "Civic", 
                      "Automatic",
                      2000,
                      6,
                      "Registered",
                      350,
                      200000,
                      nullptr,
                      nullptr);

    ButtMotors.addCar("Toyota", 
                    "Yaris", 
                    "Manual",
                    1500,
                    6,
                    "Unregistered",
                    350,
                    15000000,
                    nullptr,
                    nullptr);

    ButtMotors.addCar("Honda", 
                      "Vezel", 
                      "Automatic",
                      2000,
                      6,
                      "Unregistered",
                      350,
                      200000,
                      nullptr,
                      nullptr);

    std::cout << BOLD(FRED("OSTREAM OPERATOR\n"));
    std::cout << ButtMotors;

    std::cout << BOLD(FRED("\nSEARCH COMPANY\n"));
    ButtMotors.searchCompany("Honda");

    std::cout << BOLD(FRED("\nSEARCH AUTOMATIC\n"));
    ButtMotors.searchAutomatic();

    std::cout << BOLD(FRED("\nSEARCH MANUAL\n"));
    ButtMotors.searchManual();

    std::cout << BOLD(FRED("\nSEARCH IN PRICE RANGE\n"));
    ButtMotors.searchInPriceRange(50000,10000000);
    
    return 0;
}