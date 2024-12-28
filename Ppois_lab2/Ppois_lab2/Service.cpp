#include "Service.h"
#include <iostream>

Service::Service(const std::string& description, double cost)
    : description(description), cost(cost) {}

void Service::displayService() const {
    std::cout << "Service: " << description << " - Cost: $" << cost << std::endl;
}