#ifndef DRONE_H
#define DRONE_H

#include <string>
#include <vector>
#include <iostream>

/**
 * Purpose:
 *  Base drone with ID, name, (x,y) position. Supports a single next pointer
 *  used by Depot to form a linked list / queue / stack (one structure at a time).
 *
 * Methods (key):
 *  getters/setters, setNextDrone/getNextDrone, simple task utilities, virtual display.
 *
 * Complexity (typical):
 *  All getters/setters O(1). Printing tasks O(nTasks).
 */
class Drone {
protected:
    int id;
    std::string name;
    int x, y;
    Drone* nextDrone;                 // used by Depot chains (LL/Queue/Stack)
    std::vector<std::string> tasks;   // simple task list for demo/polymorphism

public:
    Drone(int id_=0, const std::string& name_="NA", int x_=0, int y_=0)
        : id(id_), name(name_), x(x_), y(y_), nextDrone(nullptr) {}

    virtual ~Drone() = default;

    // Linked-pointer API
    void setNextDrone(Drone* next) { nextDrone = next; }
    Drone* getNextDrone() const { return nextDrone; }

    // Basic fields
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    void setPos(int nx, int ny) { x = nx; y = ny; }

    // Tasks (minimal)
    void addTask(const std::string& t) { tasks.push_back(t); }
    const std::vector<std::string>& getTasks() const { return tasks; }
    void reverseTasks(); // defined in .cpp

    // Virtual display (polymorphic)
    virtual void displayDrone() const;
};

#endif
