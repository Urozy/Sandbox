#include "Warranty.h"
#include <iostream>

Warranty::Warranty(const std::string& terms, int durationMonths)
    : terms(terms), durationMonths(durationMonths) {}

void Warranty::displayWarranty() {
    std::cout << "Warranty: " << terms << " - Duration: " << durationMonths << " months" << std::endl;
}