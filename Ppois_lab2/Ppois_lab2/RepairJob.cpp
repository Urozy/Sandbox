#include "RepairJob.h"
#include <iostream>

RepairJob::RepairJob(const Vehicle& vehicle, const Employee& mechanic, const std::string& issue)
    : vehicle(vehicle), mechanic(mechanic), issue(issue) {}

void RepairJob::startRepair() {
    std::cout << "Mechanic " << mechanic.name << " is repairing " << vehicle.make
        << " " << vehicle.model << " - Issue: " << issue << std::endl;
}