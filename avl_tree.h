#ifndef AVLTREE_AVL_TREE_H
#define AVLTREE_AVL_TREE_H
#include "cse_set.h"
#include "tree_node.h"
#include<iostream>
#include<utility>
#include <cstdint>
#include "tree.h"
using namespace std;

class AVLTree : public Set, public Tree {
public:
    int getBalance(TreeNode* node); // 균형이 깨졌는지 check
    int insert(int key);
    TreeNode* insertRecursive(TreeNode* node, int key);
    int erase(int key);
    bool empty();
    int size();
    int find(int key);
    pair<int, int> minimum(int key);
    pair<int, int> maximum(int key);
    int rank(int key);

    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    int rankRecursive(TreeNode* node, int key);
    void inorderTraversal(TreeNode* node);
    TreeNode* getRoot(){
        return root_;
    };
private:
    TreeNode* root_;
    int32_t total_node_cnt_;
    TreeNode* findNode(int key);
    TreeNode* balancing(TreeNode* node, int key);
};
#endif//AVLTREE_AVL_TREE_H