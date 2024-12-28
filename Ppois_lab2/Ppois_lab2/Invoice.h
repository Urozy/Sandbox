#ifndef INVOICE_H
#define INVOICE_H

#include <vector>
#include "Service.h"

class Invoice {
public:
    int invoiceNumber;
    std::vector<Service> services;
    double totalCost;

    Invoice(int invoiceNumber);
    void addService(const Service& service);
    void printInvoice();
};

#endif 
