/*
* erase_test.cc
*
* Copyright (c) 2023 seungbeom Hu
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
* Author: seungbeom Hu
*/


#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../avl_tree_set_adapter.h"

using namespace std;

TEST(SET_AVLTEST, eraseTest0) {
  vector<int> insertkeys = {1};

  vector<pair<int, int> > keys = {{1, 0}};
  Set* avltree = new AVLTreeSetAdapter();

  for (auto key : insertkeys) {
    avltree->Insert(key);
  }

  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST, eraseTest1) {
  vector<int> insertkeys = {1};

  vector<pair<int, int> > keys = {{2, 0}};
  Set* avltree = new AVLTreeSetAdapter();

  for (auto key : insertkeys) {
    avltree->Insert(key);
  }

  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST, eraseTest2) {
  vector<int> insertkeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  vector<pair<int, int> > keys = {{5, 3}, {4, 0}, {2, 1}, {9, 2}};
  Set* avltree = new AVLTreeSetAdapter();

  for (auto key : insertkeys) {
    avltree->Insert(key);
  }

  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST, eraseTest3) {  // RR TEST

  vector<int> insertkeys = {1, 2, 3, 4};

  vector<pair<int, int> > keys = {{1, 1}};
  Set* avltree = new AVLTreeSetAdapter();

  for (auto key : insertkeys) {
    avltree->Insert(key);
  }

  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST, eraseTest4) {  // erase LR test

  vector<int> insertkeys = {5, 6, 1, 3};

  vector<pair<int, int> > keys = {{6, 1}};
  Set* avltree = new AVLTreeSetAdapter();

  for (auto key : insertkeys) {
    avltree->Insert(key);
  }

  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST, eraseTest5) {
  vector<int> insertkeys = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  vector<pair<int, int> > keys = {{8, 2}, {9, 1}, {2, 1},
                                  {4, 2}, {3, 1}, {1, 1}};
  Set* avltree = new AVLTreeSetAdapter();

  for (auto key : insertkeys) {
    avltree->Insert(key);
  }

  for (auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
