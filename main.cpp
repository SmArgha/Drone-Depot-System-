//To update new code into files, cd then location of finalproject then do the thing in powersheell
//g++ -std=c++17 Drone.cpp AdvancedDrone.cpp Depot.cpp SpatialTree.cpp main.cpp -o skyroute2.exe
#include <iostream>
#include <fstream>
#include "Drone.h"
#include "AdvancedDrone.h"
#include "Depot.h"
#include "SpatialTree.h"
#include "DroneManager.h"

// ---------- Logging helpers ----------

void logAddedDrone(const Drone* d) {
    std::ofstream fout("AddedDrones.txt", std::ios::app);
    if (!fout || !d) return;
    fout << d->getId() << ' ' << d->getName()
         << ' ' << d->getX() << ' ' << d->getY() << '\n';
}

void logRemovedDrone(const Drone* d) {
    std::ofstream fout("RemovedDrones.txt", std::ios::app);
    if (!fout || !d) return;
    fout << d->getId() << ' ' << d->getName()
         << ' ' << d->getX() << ' ' << d->getY() << '\n';
}

void logRandomizedOrder(const DroneManager<Drone>& manager) {
    std::ofstream fout("RandomizedOrder.txt");
    if (!fout) return;
    const auto& objs = manager.getObjects();
    for (auto* d : objs) {
        if (!d) continue;
        fout << d->getId() << ' ' << d->getName()
             << ' ' << d->getX() << ' ' << d->getY() << '\n';
    }
}

// ---------- Helper: show manager indices ----------

void printManagerWithIndices(const DroneManager<Drone>& manager) {
    const auto& objs = manager.getObjects();
    std::cout << "Manager indices:\n";
    for (int i = 0; i < (int)objs.size(); ++i) {
        std::cout << i << ": ";
        if (objs[i]) objs[i]->displayDrone();
    }
}
static void loadDronesFromFile(const std::string& filename,
                               DroneManager<Drone>& manager,
                               Depot& depot,
                               SpatialTree& tree)
{
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "WARNING: Could not open " << filename
                  << ". Start with empty fleet.\n";
        return;
    }

    std::string name;
    int id, x, y;
    int count = 0;

    while (fin >> name) {
        if (!(fin >> id)) break;
        if (!(fin >> x >> y)) break;

        Drone* d = new Drone(id, name, x, y);

        // read up to 5 tasks
        for (int i = 0; i < 5 && fin; ++i) {
            std::string taskName;
            int tx, ty;
            if (!(fin >> taskName >> tx >> ty)) {
                break;
            }
            d->addTask(taskName);
        }

        manager.addObject(d);
        depot.addDroneToLinkedList(d);
        tree.insert(d);
        ++count;
    }

    std::cout << "Loaded " << count << " drones from " << filename << ".\n";
}

// ---------- Misc helpers ----------

static Drone* makeDroneInteractive() {
    int id, x, y;
    std::string name;
    std::cout << "Enter id name x y: ";
    std::cin >> id >> name >> x >> y;
    return new Drone(id, name, x, y);
}

// ---------- main ----------

int main() {
    Depot depot;
    SpatialTree tree;
    DroneManager<Drone> manager;

    // Advanced drone for polymorphism demo
    AdvancedDrone adv(999, "Apex", 50, 50);
    adv.enableAutopilot();
    adv.updateBattery(-75.0f);
    adv.addTask("deliver_medkit");
    adv.addTask("return_base");
    adv.autoReorderTasks();

    // Load from file (make sure this name matches your file)
    loadDronesFromFile("Drones.txt", manager, depot, tree);

    std::cout << "\nPolymorphism demo (AdvancedDrone):\n";
    adv.displayDrone();

    int choice = 0;
    std::cout << "\nSkyRoute-II\n";

    while (true) {
        std::cout
          << "\n--- Drone Management Menu ---\n"
          << "1. Add Drone\n"
          << "2. Remove Drone\n"
          << "3. Show Drones\n"
          << "4. Use Linked List\n"
          << "5. Use Queue\n"
          << "6. Use Stack\n"
          << "7. Spatial Management\n"
          << "8. Sort Drones by Name\n"
          << "9. Sort Drones by ID\n"
          << "10. Sort Drones by Position\n"
          << "11. Randomize Drone Order\n"
          << "12. Print All Drone Names\n"
          << "13. Search Drone by Name\n"
          << "14. Search Drone by ID\n"
          << "15. Quit\n"
          << "Enter choice: ";

        if (!(std::cin >> choice)) break;

        switch (choice) {
        case 1: { // Add Drone
            Drone* d = makeDroneInteractive();
            manager.addObject(d);
            depot.addDroneToLinkedList(d);
            tree.insert(d);
            logAddedDrone(d);
            std::cout << "Added manual drone.\n";
            break;
        }
        case 2: { // Remove Drone (by id)
            int id;
            std::cout << "Remove id: ";
            std::cin >> id;
            Drone* d = manager.searchDroneByID(id);
            if (d) logRemovedDrone(d);
            depot.removeDroneFromLinkedList(id);
            std::cout << "Removed from linked list (if found).\n";
            break;
        }
        case 3: { // Show all drones from manager
            std::cout << "All drones (manager list):\n";
            manager.printAll();
            break;
        }
        case 4: { // Use linked list
            std::cout << "Linked list (sorted by ID):\n";
            depot.printLinkedList();
            break;
        }
        case 5: { // Queue
            int opt;
            std::cout << "Queue options: 1) enqueue by manager index 2) dequeue 3) show queue : ";
            std::cin >> opt;
            if (opt == 1) {
                printManagerWithIndices(manager);
                int idx; std::cout << "Choose index to enqueue: "; std::cin >> idx;
                Drone* d = manager.getObject(idx);
                depot.enqueueDrone(d);
            } else if (opt == 2) {
                Drone* d = depot.dequeueDrone();
                if (d) std::cout << "Dequeued: " << d->getId() << " (" << d->getName() << ")\n";
                else   std::cout << "Queue empty.\n";
            } else {
                depot.printQueue();
            }
            break;
        }
        case 6: { // Stack
            int opt;
            std::cout << "Stack options: 1) push by manager index 2) pop 3) show stack : ";
            std::cin >> opt;
            if (opt == 1) {
                printManagerWithIndices(manager);
                int idx; std::cout << "Choose index to push: "; std::cin >> idx;
                Drone* d = manager.getObject(idx);
                depot.pushDrone(d);
            } else if (opt == 2) {
                Drone* d = depot.popDrone();
                if (d) std::cout << "Popped: " << d->getId() << " (" << d->getName() << ")\n";
                else   std::cout << "Stack empty.\n";
            } else {
                depot.printStack();
            }
            break;
        }
        case 7: { // Spatial tree
            int opt;
            std::cout << "Spatial options: 1) insert by manager index 2) inorder print : ";
            std::cin >> opt;
            if (opt == 1) {
                printManagerWithIndices(manager);
                int idx; std::cout << "Choose index to insert into tree: "; std::cin >> idx;
                Drone* d = manager.getObject(idx);
                tree.insert(d);
            } else {
                tree.traverseInOrder();
            }
            break;
        }
        case 8: {
    std::cout << "Sorting drones by NAME...\n";
    manager.sortDronesByName();
    manager.printAll();  // <-- SHOW SORTED OUTPUT
    break;
}
case 9: {
    std::cout << "Sorting drones by ID...\n";
    manager.sortDronesByID();
    manager.printAll();  // <-- SHOW SORTED OUTPUT
    break;
}
case 10: {
    std::cout << "Sorting drones by POSITION...\n";
    manager.sortDronesByPosition();
    manager.printAll();  // <-- SHOW SORTED OUTPUT
    break;
}
        case 11: { // Randomize order
            manager.randomizeDroneOrder();
            logRandomizedOrder(manager);
            std::cout << "Randomized drone order and wrote to RandomizedOrder.txt.\n";
            break;
        }
        case 12: { // Print names only
            std::cout << "All drone names:\n";
            manager.printAllDroneNames();
            break;
        }
        case 13: { // Search by name
            std::string s;
            std::cout << "Search name: ";
            std::cin >> s;
            Drone* d = manager.searchDroneByName(s);
            if (d) d->displayDrone();
            else   std::cout << "Not found.\n";
            break;
        }
        case 14: { // Search by ID
            int id;
            std::cout << "Search id: ";
            std::cin >> id;
            Drone* d = manager.searchDroneByID(id);
            if (d) d->displayDrone();
            else   std::cout << "Not found.\n";
            break;
        }
        case 15:
            std::cout << "Exiting.\n";
            return 0;

        default:
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
