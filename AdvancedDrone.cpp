#include "AdvancedDrone.h"
#include <iostream>

void AdvancedDrone::displayDrone() const {
    std::cout << "[AdvDrone] id=" << getId() << ", name=" << getName()
              << ", pos=(" << getX() << "," << getY() << ")"
              << ", battery=" << std::fixed << batteryLevel << "%"
              << ", autopilot=" << (autopilotEnabled ? "ON" : "OFF")
              << ", tasks=" << getTasks().size() << "\n";
}
