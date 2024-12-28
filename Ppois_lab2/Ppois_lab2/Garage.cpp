#include "Garage.h"
#include <iostream>

void Garage::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

void Garage::showEmployees() {
    for (const auto& employee : employees) {
        std::cout << employee.name << " - " << employee.role << std::endl;
    }
}