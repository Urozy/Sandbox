#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

class Inventory {
public:
    std::vector<std::string> parts;

    void addPart(const std::string& part);
    void showInventory();
};

#endif
