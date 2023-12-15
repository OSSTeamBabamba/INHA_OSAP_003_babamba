/*
* insertTest.cpp
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
* Created on: 2023-12-14
* Author: Lee Soo-young
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include "../avl_tree.h"
#include <gtest/gtest.h>

using namespace std;

// Fixture 클래스 정의
class SETAVL_TEST : public ::testing::Test{
 protected:
  Set* avltree;

  void SetUp() override {
    avltree = new AVLTree();
  }

  void TearDown() override {
    delete avltree;
  }
};

// 트리가 처음에 비어 있는지 테스트
TEST_F(SETAVL_TEST, InitiallyEmpty){
  EXPECT_TRUE(avltree->Empty());
}

// 트리에 요소를 추가한 후 비어 있지 않은지 테스트
TEST_F(SETAVL_TEST, NotEmptyAfterInsertion){
  avltree->Insert(10);
  EXPECT_FALSE(avltree->Empty());
}

// 트리에 요소를 추가하고 삭제한 후 다시 비어 있는지 테스트
TEST_F(SETAVL_TEST, EmptyAfterErase){
  avltree->Insert(10);
  avltree->Erase(10);
  EXPECT_TRUE(avltree->Empty());
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}