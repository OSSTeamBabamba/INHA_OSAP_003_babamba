#include <cmath>
#include "avl_tree.h"
#include "avl_node.h"


using namespace std;

bool AVLTree::isBalanced(AVLNode *node) {

    int leftNodeBalancedFactor = (node->leftNode() == nullptr) ? -1 : node->leftNode()->depth();
    int rightNodeBalancedFactor = (node->rightNode() == nullptr) ? -1 : node->rightNode()->depth();


    return abs(leftNodeBalancedFactor - rightNodeBalancedFactor < 2) ? true : false;
}


int AVLTree::insert(int key) {
    return NULL;
}
int AVLTree::erase(int key) {
    return NULL;
}

bool AVLTree::empty() {
    return NULL;
}
int AVLTree::size() {
    return NULL;
}

int AVLTree::find(int key) {
    return NULL;
}
AVLNode *AVLTree::findNode(int key) {
    return NULL;
}


pair<int,int> AVLTree::minimum(int key) {
    return NULL;
}

pair<int,int> AVLTree::maximum(int key) {

    AVLNode *node = findNode(key);

    while (node->rightNode() != nullptr) {
        node = node->rightNode();
    }
    return make_pair(node->key(), node->depth());
}

int AVLTree::rank(int key) {
    return NULL;
}
AVLNode AVLTree::*rotateRight(AVLNode *node) {
    return NULL;
}
AVLNode AVLTree::*rotateLeft(AVLNode *node) {
    return NULL;
}