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
# SkyRoute-II

## Project Overview

SkyRoute-II is a C++ drone-fleet management and logistics simulation. The system manages a fleet of autonomous drones and demonstrates the use of linked lists, queues, stacks, binary trees, templates, inheritance, and polymorphism.

The program loads drone information and delivery tasks from a text file and allows the user to manage the fleet through a menu-driven interface.

## Main Features

- Add and remove drones
- Manage drones using a sorted linked list
- Dispatch drones using a FIFO queue
- Manage maintenance/recovery using a LIFO stack
- Organize drones spatially using a binary search tree
- Search drones by name or ID
- Sort drones by name, ID, or position
- Randomize drone order
- Demonstrate template-based programming with `DroneManager<T>`
- Demonstrate inheritance and polymorphism using `AdvancedDrone`
- Record user-generated changes in output text files

## Data Structures

### Linked List

The Depot maintains a linked list of drones ordered by ascending drone ID.

```text
Head
 ↓
Drone 87 → Drone 102 → Drone 105 → Drone 109 → ...

---
Drones.txt
## Text Files and Generated Output

The project uses several text files to store input data and record
different states of the drone depot.

### Drones.txt

`Drones.txt` is the main input file for the program.

It contains the initial information for the drones loaded into the Depot.
The program reads the first 10 drones from this file. If more than 10
drones are present, the additional drones are ignored.

Each drone contains:

- Drone name
- Drone ID
- Initial position
- Five task names
- Five task positions

Example:

```text
Alpha
101
50 80
Grocery 10 20
Electronics 15 25
Medical 5 30
Book 3 25
Skin_Care 7 29
