#include "Payment.h"
#include <iostream>

Payment::Payment(double amount, const std::string& method)
    : amount(amount), method(method) {}

void Payment::processPayment() {
    std::cout << "Processing payment of $" << amount << " via " << method << std::endl;
}