/*
* tree_node.h
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

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstdint>

#include "node.h"

class TreeNode : public Node {
 public:
  TreeNode()
      : Node(0),
        depth_(0),
        height_(0),
        parentNode_(nullptr),
        leftNode_(nullptr),
        rightNode_(nullptr){};
  TreeNode(int32_t key, TreeNode* parentNode, TreeNode* leftNode,
           TreeNode* rightNode)
      : Node(key),
        depth_(0),
        height_(0),
        parentNode_(parentNode),
        leftNode_(leftNode),
        rightNode_(rightNode){};

 public:
  int32_t depth() const;
  void setDepth(int32_t depth);
  int32_t height() const;
  void setHeight(int32_t height);
  TreeNode* parentNode() const;
  void setParentNode(TreeNode* parentNode);
  TreeNode* leftNode() const;
  void setLeftNode(TreeNode* leftNode);
  TreeNode* rightNode() const;
  void setRightNode(TreeNode* rightNode);

 private:
  int32_t depth_;
  int32_t height_;
  TreeNode* parentNode_;
  TreeNode* leftNode_;
  TreeNode* rightNode_;
};

#endif
