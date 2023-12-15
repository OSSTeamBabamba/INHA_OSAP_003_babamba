/*
* Maximum_test.cpp
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
* Author: Lee Soo-young
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include "../avl_tree.h"
#include <gtest/gtest.h>

using namespace std;

TEST(SET_AVLTEST, FindMaximumDepth) {
  Set* avlTree = new AVLTree();
  vector<int> keys = {10,5,15,3,7};
  //AVL트리에 keys 삽입
  for(auto key : keys) avlTree->Insert(key);

  // Test the Maximum function
  EXPECT_EQ(avlTree->Maximum(10).first, 1);  // 10을 루트로 하는 서브트리의 depth는 1
  EXPECT_EQ(avlTree->Maximum(5).first, 2);  // 5를 루트로 하는 서브트리의 depth는 2
  EXPECT_EQ(avlTree->Maximum(15).first, 1);  // 15를 루트로 하는 서브트리의 depth는 1
  ASSERT_EQ(avlTree->Maximum(20).first, -1); // 20은 해당 트리에 존재하지 않기에 -1 반환
}

//Insert 후 Maximum Node
TEST(SET_AVLTEST, FindMaximumNode) {
  Set* avlTree = new AVLTree();
  vector<int> keys = {10,5,15,3,7};
  //AVL트리에 keys 삽입
  for(auto key : keys) avlTree->Insert(key);

  // Test the Maximum function
  EXPECT_EQ(avlTree->Maximum(10), make_pair(1,15));  // 10을 루트로 하는 서브트리의 Node는 (depth, Key)는 (1, 15)
  EXPECT_EQ(avlTree->Maximum(5), make_pair(2,7));  // 5를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,7)
  EXPECT_EQ(avlTree->Maximum(15), make_pair(1,15));  // 15를 루트로 하는 서브트리의 Node는 (depth, Key)는 (1, 15)
  EXPECT_EQ(avlTree->Maximum(3), make_pair(2,3));  // 3를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,3)
  EXPECT_EQ(avlTree->Maximum(7), make_pair(2,7));  // 7를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,7)
  ASSERT_EQ(avlTree->Maximum(20), make_pair(-1,-1)); // 20은 해당 트리에 존재하지 않기에 (-1,-1)이 반환
}


//삽입 및 삭제 연산 후 Maximum 노드
TEST(SET_AVLTEST, FindMaximumAfterErase) {
  Set* avlTree = new AVLTree();
  vector<int> keys = {10,5,15,3,7,12,18};
  for(auto key : keys) avlTree->Insert(key);  // AVL트리에 keys 삽입

  // Test the Maximum function
  EXPECT_EQ(avlTree->Maximum(3), make_pair(2,3));  // 3을 루트로 하는 서브트리의 (depth, Key)는 (2,3)
  EXPECT_EQ(avlTree->Maximum(10), make_pair(2,18));  // 10를 루트로 하는 서브트리의 (depth, Key)는 (2,18)
  EXPECT_EQ(avlTree->Maximum(15), make_pair(2,18));  // 15를 루트로 하는 서브트리의 (depth, Key)는 (2,18)

  avlTree->Erase(3); // AVL 트리에서 3을 키로 가진 노드 삭제
  EXPECT_EQ(avlTree->Maximum(10), make_pair(2,18)); //10을 루트로 하는 서브트리의 Maximum노드는 3에서 2로 변경
  ASSERT_EQ(avlTree->Maximum(3), make_pair(-1,-1)); //삭제된 3은 찾을 수 없다.
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}