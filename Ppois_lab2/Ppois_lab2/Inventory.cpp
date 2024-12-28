#include "Inventory.h"
#include <iostream>

void Inventory::addPart(const std::string& part) {
    parts.push_back(part);
}

void Inventory::showInventory() {
    for (const auto& part : parts) {
        std::cout << part << std::endl;
    }
}
