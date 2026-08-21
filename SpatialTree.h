#ifndef SPATIAL_TREE_H
#define SPATIAL_TREE_H

#include "Drone.h"
#include <iostream>

/**
 * Purpose:  Binary search tree on (x,y) — primary key x, tiebreaker y.
 *  Used for spatial indexing and nearest-ish lookup demo.
 * Complexity:
 *  Average O(log n) insert/search; worst O(n) if unbalanced.
 */

class SpatialNode {
public:
    Drone* drone;
    SpatialNode* left;
    SpatialNode* right;
    explicit SpatialNode(Drone* d) : drone(d), left(nullptr), right(nullptr) {}
};

class SpatialTree {
    SpatialNode* root;

    SpatialNode* insertRec(SpatialNode* n, Drone* d);
    Drone* searchRec(SpatialNode* n, int x, int y) const; // simple BST search by exact key
    void inOrder(SpatialNode* n) const;
    void preOrder(SpatialNode* n) const;
    void postOrder(SpatialNode* n) const;

public:
    SpatialTree() : root(nullptr) {}
    void insert(Drone* d) { root = insertRec(root, d); }
    Drone* search(int x, int y) const { return searchRec(root, x, y); }
    void traverseInOrder() const { inOrder(root); std::cout << "\n"; }
    void traversePreOrder() const { preOrder(root); std::cout << "\n"; }
    void traversePostOrder() const { postOrder(root); std::cout << "\n"; }
};

#endif
