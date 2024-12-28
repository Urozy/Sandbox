#ifndef REPAIRJOB_H
#define REPAIRJOB_H

#include <string>
#include "Vehicle.h"
#include "Employee.h"

class RepairJob {
public:
    Vehicle vehicle;
    Employee mechanic;
    std::string issue;

    RepairJob(const Vehicle& vehicle, const Employee& mechanic, const std::string& issue);
    void startRepair();
};

#endif 
