#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
public:
    double amount;
    std::string method;

    Payment(double amount, const std::string& method);
    void processPayment();
};

#endif 
