#ifndef DRONE_MANAGER_H
#define DRONE_MANAGER_H

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

/**
 * Purpose:
 *  Generic manager over pointers to objects (e.g., Drone*).
 *  Sorting/searching assume T exposes: getName(), getId(), getX(), getY(), displayDrone().
 *
 * Complexity:
 *  add/get O(1). Sort O(n log n). Randomize O(n). Searches linear here (O(n)) for simplicity.
 */
template <typename T>
class DroneManager {
    std::vector<T*> objects;

public:
    void addObject(T* obj) { objects.push_back(obj); }

    T* getObject(int index) {
        if (index < 0 || index >= (int)objects.size()) return nullptr;
        return objects[index];
    }

    // NEW: const access to underlying vector (for logging)
    const std::vector<T*>& getObjects() const { return objects; }

    void sortDronesByName() {
        std::sort(objects.begin(), objects.end(),
                  [](T* a, T* b){ return a->getName() < b->getName(); });
    }

    void sortDronesByID() {
        std::sort(objects.begin(), objects.end(),
                  [](T* a, T* b){ return a->getId() < b->getId(); });
    }

    void sortDronesByPosition() {
        std::sort(objects.begin(), objects.end(),
                  [](T* a, T* b){
                      if (a->getX() != b->getX()) return a->getX() < b->getX();
                      return a->getY() < b->getY();
                  });
    }

    void randomizeDroneOrder() {
        std::random_device rd; std::mt19937 gen(rd());
        std::shuffle(objects.begin(), objects.end(), gen);
    }

    T* searchDroneByName(const std::string& name) {
        for (auto* p : objects) if (p->getName() == name) return p;
        return nullptr;
    }

    T* searchDroneByID(int id) {
        for (auto* p : objects) if (p->getId() == id) return p;
        return nullptr;
    }

    void printAllDroneNames() {
        for (auto* p : objects) std::cout << p->getName() << "\n";
    }

    void printAll() {
        for (auto* p : objects) p->displayDrone();
    }
};

#endif
