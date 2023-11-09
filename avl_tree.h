#ifndef AVLTREE_AVL_TREE_H
#define AVLTREE_AVL_TREE_H

#include "cse_set.h"
#include "avl_node.h"

class AVLTree : public Set{

protected:
    bool isBalanced(AVLNode *node); // 균형이 깨졌는지 check

    int insert(int key);
    int erase(int key);

    bool empty();
    int size();

    int find(int key);
    int minimum(int key);
    int maximum(int key);
    int rank(int key);

    AVLNode* rotateRight(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);

private:
    AVLNode *root_;
    int32_t total_node_cnt_;
    AVLNode* findNode(int key);

};
#endif//AVLTREE_AVL_TREE_H
