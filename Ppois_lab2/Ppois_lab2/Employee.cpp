#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& name, const std::string& role)
    : name(name), role(role) {}

void Employee::performDuty() {
    std::cout << name << " is performing their role as a " << role << std::endl;
}