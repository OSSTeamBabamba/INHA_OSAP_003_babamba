#ifndef AVLTREE_AVL_TREE_H
#define AVLTREE_AVL_TREE_H
#include "cse_set.h"
#include "tree_node.h"
#include<iostream>
#include<utility>
#include <cstdint>
#include "tree.h"
using namespace std;

class AVLTree : public Tree {
public:

    TreeNode* root(){
        return root_;
    };
protected:
    TreeNode* root_;
    int32_t total_node_cnt_;
    TreeNode* FindNode(int key);
    TreeNode* InsertRecursive(TreeNode* node, int key);
    TreeNode* EraseRecursive(TreeNode* node, int key);
    TreeNode* Balancing(TreeNode* node, int key);
    TreeNode* EraseBalancing(TreeNode* node, int key);
    TreeNode* RotateRight(TreeNode* node);
    TreeNode* RotateLeft(TreeNode* node);
    int RankRecursive(TreeNode* node, int key);
    void InorderTraversal(TreeNode* node);
    int SubtreeSize(TreeNode* node);
    int getBalance(TreeNode* node); // 균형이 깨졌는지 check

};
#endif//AVLTREE_AVL_TREE_H