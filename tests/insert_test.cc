/*
* insert_test.cc
*
* Copyright (c) 2023 seungbeomHu,Lee Soo-young
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
* Author: seungbeomHu,Lee Soo-young
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <utility>
#include <vector>

#include "../avl_tree_set_adapter.h"

using namespace std;

TEST(SET_AVLTEST, InsertTest0) {
  vector<pair<int, int> > keys = {{10, 0}};
  Set* avltree = new AVLTreeSetAdapter();
  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Insert(key.first));
  }
}

TEST(SET_AVLTEST, InsertTest1) {
  vector<pair<int, int> > keys = {{10, 0}, {9, 1}, {8, 1}, {7, 2}, {6, 2},
                                  {5, 2},  {4, 2}, {3, 3}, {2, 3}, {1, 3}};
  Set* avltree = new AVLTreeSetAdapter();
  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Insert(key.first));
  }
}

TEST(SET_AVLTEST, InsertTest2) {
  vector<pair<int, int> > keys = {{1, 0}, {2, 1}, {3, 1}, {4, 2}, {5, 2},
                                  {6, 2}, {7, 2}, {8, 3}, {9, 3}, {10, 3}};
  Set* avltree = new AVLTreeSetAdapter();
  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Insert(key.first));
  }
}

TEST(SET_AVLTEST, InsertTest3) {
  vector<pair<int, int> > keys = {{10, 0}, {80, 1}, {30, 0}, {3, 2},
                                  {5, 1},  {8, 2},  {70, 1}};
  Set* avltree = new AVLTreeSetAdapter();
  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Insert(key.first));
  }
}

TEST(SET_AVLTEST, InsertTest4) {
  vector<pair<int, int> > keys = {
      {72, 0},  {99, 1},  {30, 1},  {1, 2}, {40, 2}, {50, 2}, {130, 3},
      {200, 3}, {70, 3},  {33, 2},  {2, 3}, {73, 4}, {90, 3}, {63, 2},
      {57, 4},  {500, 4}, {100, 4}, {8, 4}, {5, 4},  {43, 4}};
  Set* avltree = new AVLTreeSetAdapter();
  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Insert(key.first));
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}