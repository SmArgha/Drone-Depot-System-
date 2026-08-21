# Drone-Depot-System-
C++ Drone fleet management system that uses classes, vectors, sorting, binary search, opertor overloading, file I/O, and route optimization algorithms.

## Description

The Drone Depot Management System is a C++ program designed to manage
a fleet of delivery drones.

Each drone has its identity, initial position, five delivery tasks, and
a position for each task. The Depot class manages the collection of drones
and provides operations for sorting, searching, modifying, copying, swapping,
and storing drone information.

The project also includes route optimization algorithms that determine
efficient delivery routes for each drone.

---

## Features

### Drone Management

Each Drone contains:

- Drone name
- Drone ID
- Initial position (x, y)
- Five task names
- Five task positions

The Drone class supports:

- Getters and setters
- Index-based setters
- Alphabetical task sorting
- Task/position synchronization during sorting
- Drone display
- Copying drone data
- Swapping task data between drones---

## Depot Management

The Depot class manages a collection of Drone objects.

Supported operations include:

1. Sort drones by name
2. Sort drones by ID
3. Sort drones by position
4. Randomize drone order
5. Add a drone
6. Retrieve a drone
7. Search by name
8. Search by ID
9. Write depot information to a file
10. Swap drone data
11. Insert a drone task
12. Copy drone data
13. Display all drone names
14. Sort task data ascending
15. Sort task data descending

---

## Route Optimization

The project includes two route-planning approaches.

### Greedy Route
The drone starts at its initial position and repeatedly travels to
the nearest unvisited task.

After visiting all tasks, the drone returns to its starting position.

This approach is fast but does not always produce the shortest possible route.

### Global Optimal Route

The program evaluates possible task orders to determine the shortest
complete route.

The route:

1. Starts at the drone's initial position
2. Visits every task exactly once
3. Returns to the initial position

The program compares the results of the greedy and globally optimal approaches.

## Input File

The program reads drone information from:

```text
Drones.txt
