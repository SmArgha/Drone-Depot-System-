#ifndef DEPOT_H
#define DEPOT_H
#include "Drone.h"
#include <iostream>
/**
 * Purpose:
 *  Manages three pointer-based structures over Drone objects:
 *   - Sorted linked list by ID (head)
 *   - FIFO queue (queueFront/queueRear)
 *   - LIFO stack (stackTop)
 *
 * Notes:
 *  Each structure uses Drone::nextDrone as its link. A drone should be
 *  in at most ONE of these chains at a time. Before inserting, we null its next.
 *
 * Complexity:
 *  add/remove in sorted LL: O(n). enqueue/dequeue: O(1). push/pop: O(1).
 */
class Depot {
    Drone* head;        // sorted list by id
    Drone* queueFront;  // queue pointers
    Drone* queueRear;
    Drone* stackTop;    // stack pointer

public:
    Depot() : head(nullptr), queueFront(nullptr), queueRear(nullptr), stackTop(nullptr) {}
    ~Depot() = default; // (ownership left to caller / manager in this simple demo)

    // Sorted Linked List (by id ascending)
    void addDroneToLinkedList(Drone* d);
    void removeDroneFromLinkedList(int id);

    // Queue (FIFO)
    void enqueueDrone(Drone* d);
    Drone* dequeueDrone();

    // Stack (LIFO)
    void pushDrone(Drone* d);
    Drone* popDrone();

    // Simple printers
    void printLinkedList() const;
    void printQueue() const;
    void printStack() const;

    // Accessors for testing
    Drone* getHead() const { return head; }
    Drone* getQueueFront() const { return queueFront; }
    Drone* getStackTop() const { return stackTop; }
};

#endif
