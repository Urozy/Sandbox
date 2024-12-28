#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    std::string name;
    std::string role;

    Employee(const std::string& name, const std::string& role);
    void performDuty();
};

#endif 
