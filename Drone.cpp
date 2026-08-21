#include "Drone.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Drone::reverseTasks() {
    std::reverse(tasks.begin(), tasks.end());
}

void Drone::displayDrone() const {
    std::cout << "[Drone] id=" << id << ", name=" << name
              << ", pos=(" << x << "," << y << ")"
              << ", tasks=" << tasks.size() << "\n";
}

