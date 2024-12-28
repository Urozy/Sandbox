#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Customer.h"
#include "Vehicle.h"

class Appointment {
public:
    Customer customer;
    Vehicle vehicle;
    std::string date;

    Appointment(const Customer& customer, const Vehicle& vehicle, const std::string& date);
    void confirm();
};

#endif
