/*
* avl_tree.h
*
* Copyright (c) 2023 seungbeomHu,Lee Soo-young, 박성훈, 정건우
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Created on: 2023-12-14
* Author: seungbeomHu,Lee Soo-young, 박성훈, 정건우
 */

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