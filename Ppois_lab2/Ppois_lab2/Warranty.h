#ifndef WARRANTY_H
#define WARRANTY_H

#include <string>

class Warranty {
public:
    std::string terms;
    int durationMonths;

    Warranty(const std::string& terms, int durationMonths);
    void displayWarranty();
};

#endif
