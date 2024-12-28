#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, const std::string& phoneNumber)
    : name(name), phoneNumber(phoneNumber) {}

void Customer::contact() {
    std::cout << "Contacting " << name << " at " << phoneNumber << std::endl;
}
