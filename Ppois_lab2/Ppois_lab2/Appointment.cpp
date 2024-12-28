#include "Appointment.h"
#include <iostream>

Appointment::Appointment(const Customer& customer, const Vehicle& vehicle, const std::string& date)
    : customer(customer), vehicle(vehicle), date(date) {}

void Appointment::confirm() {
    std::cout << "Appointment confirmed for " << customer.name
        << " with " << vehicle.make << " " << vehicle.model
        << " on " << date << std::endl;
}