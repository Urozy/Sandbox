#ifndef SERVICE_H
#define SERVICE_H

#include <string>

class Service {
public:
    std::string description;
    double cost;

    Service(const std::string& description, double cost);
    void displayService() const;
};

#endif
