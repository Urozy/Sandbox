#include <iostream>
#include "Vehicle.h"
#include "Customer.h"
#include "Employee.h"
#include "Service.h"
#include "Invoice.h"
#include "Appointment.h"
#include "Garage.h"
#include "Inventory.h"
#include "RepairJob.h"
#include "WaitingArea.h"
#include "Warranty.h"
#include "DiagnosticTool.h"
#include "ParkingLot.h"
#include "Payment.h"
#include "Feedback.h"

int main() {

    Vehicle car("Toyota", "Camry", 2020);
    car.displayInfo();

    Customer customer("John Doe", "29 212-23-12");
    customer.contact();

    Employee mechanic("Jane Smith", "Mechanic");
    mechanic.performDuty();

    Service oilChange("Oil Change", 39.99);
    oilChange.displayService();

    Invoice invoice(1001);
    invoice.addService(oilChange);
    invoice.printInvoice();

    Appointment appointment(customer, car, "2024-12-30");
    appointment.confirm();

    Garage garage;
    garage.addEmployee(mechanic);
    garage.showEmployees();

    Inventory inventory;
    inventory.addPart("Brake Pads");
    inventory.addPart("Oil Filter");
    inventory.showInventory();

    RepairJob repairJob(car, mechanic, "Replace brake pads");
    repairJob.startRepair();

    WaitingArea waitingArea(10);
    waitingArea.checkAvailability();

    Warranty warranty("Covers engine and transmission", 24);
    warranty.displayWarranty();

    DiagnosticTool diagnosticTool("OBD-II Scanner");
    diagnosticTool.runDiagnostics(car);

    ParkingLot parkingLot(50);
    parkingLot.checkCapacity();

    Payment payment(39.99, "Credit Card");
    payment.processPayment();

    Feedback feedback("John Doe", "Great service, highly recommend!");
    feedback.displayFeedback();

    return 0;
}
