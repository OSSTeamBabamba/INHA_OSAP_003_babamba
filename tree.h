#ifndef AVLTREESTL_TREE_H
#define AVLTREESTL_TREE_H

#include "tree_node.h"
#include "node.h"

class Tree {
public:
    int insert(int key);
    int erase(int key);
    bool empty();
    int size();
    int find(int key);
    int rank(int key);

protected:
    TreeNode* root_;
    int32_t total_node_cnt;
};


#endif//AVLTREESTL_TREE_H
