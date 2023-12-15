/*
* rank_test.cc
*
* Copyright (c) 2023 Lee Soo-young
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
* Created on: 2023-12-15
* Author: 박성훈
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <utility>
#include <vector>

#include "../avl_tree_set_adapter.h"

using namespace std;

// Insert 후 Rank
TEST(SET_AVLTEST, rankTest0) {
  Set* avlTree = new AVLTreeSetAdapter();
  vector<int> keys = {10, 5, 15, 3, 7, 12, 18};
  for (auto key : keys) avlTree->Insert(key);

  // Test the Rank function
  EXPECT_EQ(avlTree->Rank(10).second, 4);  // 10의 랭크는 4
  EXPECT_EQ(avlTree->Rank(3).second, 1);   // 3의 랭크는 1
  EXPECT_EQ(avlTree->Rank(18).second, 7);  // 18의 랭크는 7
  ASSERT_EQ(avlTree->Rank(20).first,
            -1);  // 20은 해당 트리에 존재하지 않기에 -1 반환
}

// Insert 후 해당 노드의 깊이
TEST(SET_AVLTEST, rankTest1) {
  Set* avlTree = new AVLTreeSetAdapter();
  vector<int> keys = {10, 5, 15, 3, 7, 12, 18};
  for (auto key : keys) avlTree->Insert(key);

  // Test the Rank function
  EXPECT_EQ(avlTree->Rank(10).first, 0);  // 10의 depth는 0
  EXPECT_EQ(avlTree->Rank(3).first, 2);   // 3의 depth는 2
  EXPECT_EQ(avlTree->Rank(18).first, 2);  // 18의 depth는 2
  ASSERT_EQ(avlTree->Rank(20).first,
            -1);  // 20은 해당 트리에 존재하지 않기에 -1 반환
}

TEST(SET_AVLTEST, rankTest2) {
  Set* avlTree = new AVLTreeSetAdapter();
  vector<int> keys = {10, 5, 15, 3, 7, 12, 18};
  for (auto key : keys) avlTree->Insert(key);  // AVL트리에 keys 삽입

  // Test the Rank function
  EXPECT_EQ(avlTree->Rank(10), make_pair(0, 4));  // 10의 (depth, rank)는 (0, 4)
  EXPECT_EQ(avlTree->Rank(3), make_pair(2, 1));  // 3의 (depth, rank)는 (2, 1)
  EXPECT_EQ(avlTree->Rank(18), make_pair(2, 7));  // 18의 (depth, rank)는 (2, 7)
  ASSERT_EQ(avlTree->Rank(20).first,
            -1);  // 20은 해당 트리에 존재하지 않기에 -1반환
}

// 삽입 및 삭제 연산 후 Rank
TEST(SET_AVLTEST, rankTest3) {
  Set* avlTree = new AVLTreeSetAdapter();
  vector<int> keys = {10, 5, 15, 3, 7, 12, 18};
  for (auto key : keys) avlTree->Insert(key);

  // Test the Rank function
  EXPECT_EQ(avlTree->Rank(10).second, 4);  // 10의 랭크는 4
  EXPECT_EQ(avlTree->Rank(3).second, 1);   // 3의 랭크는 1
  EXPECT_EQ(avlTree->Rank(18).second, 7);  // 18의 랭크는 7

  avlTree->Erase(3);  // AVL 트리에서 3을 키로 가진 노드 삭제
  EXPECT_EQ(avlTree->Rank(10).second,
            3);  // 10을 루트로 하는 서브트리의 Rank 4->3으로 변경
  ASSERT_EQ(avlTree->Rank(3).second, 0);  // 삭제된 3은 찾을 수 없다.
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}