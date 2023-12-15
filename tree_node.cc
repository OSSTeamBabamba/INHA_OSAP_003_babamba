/*
* tree_node.cc
*
* Copyright (c) seungbeomHu,Lee Soo-young, 박성훈, 정건우
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


#include "tree_node.h"
using namespace std;

int32_t TreeNode::depth() const { return depth_; }
void TreeNode::setDepth(int32_t depth) { depth_ = depth; }
int32_t TreeNode::height() const { return height_; }
void TreeNode::setHeight(int32_t height) { height_ = height; }

TreeNode* TreeNode::parentNode() const { return parentNode_; }
void TreeNode::setParentNode(TreeNode* leftNode) { parentNode_ = leftNode; }

TreeNode* TreeNode::leftNode() const { return leftNode_; }
void TreeNode::setLeftNode(TreeNode* leftNode) { leftNode_ = leftNode; }
TreeNode* TreeNode::rightNode() const { return rightNode_; }
void TreeNode::setRightNode(TreeNode* rightNode) { rightNode_ = rightNode; }