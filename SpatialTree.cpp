#include "SpatialTree.h"

static bool lessXY(const Drone* a, const Drone* b){
    if (a->getX() != b->getX()) return a->getX() < b->getX();
    return a->getY() < b->getY();
}

SpatialNode* SpatialTree::insertRec(SpatialNode* n, Drone* d) {
    if (!n) return new SpatialNode(d);
    if (lessXY(d, n->drone)) n->left = insertRec(n->left, d);
    else                     n->right = insertRec(n->right, d);
    return n;
}

Drone* SpatialTree::searchRec(SpatialNode* n, int x, int y) const {
    if (!n) return nullptr;
    if (n->drone->getX() == x && n->drone->getY() == y) return n->drone;
    if (x < n->drone->getX() || (x == n->drone->getX() && y < n->drone->getY()))
        return searchRec(n->left, x, y);
    return searchRec(n->right, x, y);
}

void SpatialTree::inOrder(SpatialNode* n) const {
    if (!n) return;
    inOrder(n->left);
    n->drone->displayDrone();
    inOrder(n->right);
}
void SpatialTree::preOrder(SpatialNode* n) const {
    if (!n) return;
    n->drone->displayDrone();
    preOrder(n->left);
    preOrder(n->right);
}
void SpatialTree::postOrder(SpatialNode* n) const {
    if (!n) return;
    postOrder(n->left);
    postOrder(n->right);
    n->drone->displayDrone();
}
