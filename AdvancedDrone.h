#ifndef ADVANCED_DRONE_H
#define ADVANCED_DRONE_H
#include "Drone.h"
/**
 * Purpose: Derived drone with battery + simple autopilot flag. Demonstrates polymorphism.
 * Methods: enableAutopilot(), updateBattery(delta), autoReorderTasks() → reverse tasks if battery<30%.
 * * Complexity: *  O(1) except autoReorderTasks() which is O(nTasks).  */
class AdvancedDrone : public Drone {
    float batteryLevel;      // percentage [0..100]
    bool autopilotEnabled;

public:
    AdvancedDrone(int id_=0, const std::string& name_="NA", int x_=0, int y_=0)
        : Drone(id_, name_, x_, y_), batteryLevel(100.0f), autopilotEnabled(false) {}

    void enableAutopilot() { autopilotEnabled = true; }
    void updateBattery(float delta) {
        batteryLevel += delta;
        if (batteryLevel < 0) batteryLevel = 0;
        if (batteryLevel > 100) batteryLevel = 100;
    }

    void autoReorderTasks() {
        if (batteryLevel < 30.0f) reverseTasks();
    }

    void displayDrone() const override;
};

#endif
