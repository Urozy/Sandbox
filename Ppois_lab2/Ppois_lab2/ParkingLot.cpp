#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : capacity(capacity) {}

void ParkingLot::checkCapacity() {
    std::cout << "Parking lot has capacity for " << capacity << " vehicles." << std::endl;
}