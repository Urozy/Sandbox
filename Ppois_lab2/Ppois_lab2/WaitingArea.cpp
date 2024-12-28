#include "WaitingArea.h"
#include <iostream>

WaitingArea::WaitingArea(int seats) : seats(seats) {}

void WaitingArea::checkAvailability() {
    std::cout << "Waiting area has " << seats << " seats available." << std::endl;
}