#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    std::string make;
    std::string model;
    int year;

    Vehicle(const std::string& make, const std::string& model, int year);
    void displayInfo();
};

#endif 
