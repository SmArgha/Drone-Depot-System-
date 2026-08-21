#include "Depot.h"
static void resetNext(Drone* d){ if(d) d->setNextDrone(nullptr); }
// ----- Linked list (sorted by id) -----
void Depot::addDroneToLinkedList(Drone* d) {
    if (!d) return;
    resetNext(d);

    if (!head || d->getId() < head->getId()) {
        d->setNextDrone(head);
        head = d;
        return;
    }
    Drone* cur = head;
    while (cur->getNextDrone() && cur->getNextDrone()->getId() < d->getId())
        cur = cur->getNextDrone();
    d->setNextDrone(cur->getNextDrone());
    cur->setNextDrone(d);
}

void Depot::removeDroneFromLinkedList(int id) {
    if (!head) return;
    if (head->getId() == id) {
        head = head->getNextDrone();
        return;
    }
    Drone* cur = head;
    while (cur->getNextDrone() && cur->getNextDrone()->getId() != id)
        cur = cur->getNextDrone();
    if (cur->getNextDrone()) {
        cur->setNextDrone(cur->getNextDrone()->getNextDrone());
    }
}

// ----- Queue -----
void Depot::enqueueDrone(Drone* d) {
    if (!d) return;
    resetNext(d);
    if (!queueRear) {
        queueFront = queueRear = d;
    } else {
        queueRear->setNextDrone(d);
        queueRear = d;
    }
}

Drone* Depot::dequeueDrone() {
    if (!queueFront) return nullptr;
    Drone* out = queueFront;
    queueFront = queueFront->getNextDrone();
    if (!queueFront) queueRear = nullptr;
    out->setNextDrone(nullptr);
    return out;
}

// ----- Stack -----
void Depot::pushDrone(Drone* d) {
    if (!d) return;
    resetNext(d);
    d->setNextDrone(stackTop);
    stackTop = d;
}

Drone* Depot::popDrone() {
    if (!stackTop) return nullptr;
    Drone* out = stackTop;
    stackTop = stackTop->getNextDrone();
    out->setNextDrone(nullptr);
    return out;
}

// ----- Printers -----
void Depot::printLinkedList() const {
    std::cout << "[LL] head -> ";
    for (Drone* p = head; p; p = p->getNextDrone())
        std::cout << p->getId() << "(" << p->getName() << ") -> ";
    std::cout << "NULL\n";
}

void Depot::printQueue() const {
    std::cout << "[Q] front -> ";
    for (Drone* p = queueFront; p; p = p->getNextDrone())
        std::cout << p->getId() << "(" << p->getName() << ") -> ";
    std::cout << "NULL\n";
}

void Depot::printStack() const {
    std::cout << "[S] top -> ";
    for (Drone* p = stackTop; p; p = p->getNextDrone())
        std::cout << p->getId() << "(" << p->getName() << ") -> ";
    std::cout << "NULL\n";
}
