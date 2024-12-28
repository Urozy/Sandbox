#include "DiagnosticTool.h"
#include <iostream>

DiagnosticTool::DiagnosticTool(const std::string& toolName) : toolName(toolName) {}

void DiagnosticTool::runDiagnostics(const Vehicle& vehicle) {
    std::cout << "Running diagnostics on " << vehicle.make << " " << vehicle.model
        << " using " << toolName << std::endl;
}