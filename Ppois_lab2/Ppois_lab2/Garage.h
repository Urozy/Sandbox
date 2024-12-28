#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include "Employee.h"

class Garage {
public:
    std::vector<Employee> employees;

    void addEmployee(const Employee& employee);
    void showEmployees();
};

#endif
