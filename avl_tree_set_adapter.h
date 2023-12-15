/*
* avl_tree_set_adpter.h
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

#ifndef AVLTREESTL_AVL_TREE_SET_ADAPTER_H
#define AVLTREESTL_AVL_TREE_SET_ADAPTER_H

#include "avl_tree.h"
#include "cse_set.h"

class AVLTreeSetAdapter : public Set, AVLTree {
 public:
  int Insert(int key);
  int Erase(int key);
  bool Empty();
  int Size();
  int Find(int key);
  pair<int, int> Rank(int key);
  pair<int, int> Minimum(int key);
  pair<int, int> Maximum(int key);
};

#endif  // AVLTREESTL_AVL_TREE_SET_ADAPTER_H
