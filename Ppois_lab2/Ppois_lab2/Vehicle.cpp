#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& make, const std::string& model, int year)
    : make(make), model(model), year(year) {}

void Vehicle::displayInfo() {
    std::cout << year << " " << make << " " << model << std::endl;
}
