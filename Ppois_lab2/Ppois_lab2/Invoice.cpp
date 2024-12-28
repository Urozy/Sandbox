#include "Invoice.h"
#include <iostream>

Invoice::Invoice(int invoiceNumber) : invoiceNumber(invoiceNumber), totalCost(0) {}

void Invoice::addService(const Service& service) {
    services.push_back(service);
    totalCost += service.cost;
}

void Invoice::printInvoice() {
    std::cout << "Invoice #" << invoiceNumber << std::endl;
    for (const auto& service : services) {
        service.displayService();
    }
    std::cout << "Total: $" << totalCost << std::endl;
}