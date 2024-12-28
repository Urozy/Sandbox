#ifndef DIAGNOSTICTOOL_H
#define DIAGNOSTICTOOL_H

#include <string>
#include "Vehicle.h"

class DiagnosticTool {
public:
    std::string toolName;

    DiagnosticTool(const std::string& toolName);
    void runDiagnostics(const Vehicle& vehicle);
};

#endif 
