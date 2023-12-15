/*
* sizeTest.cpp
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

// 값이 매개변수화된 테스트 Fixture 클래스 정의
class SET_AVLTEST : public ::testing::TestWithParam<std::vector<int>>{
 protected:
  Set* avltree;

  void SetUp() override{
    avltree = new AVLTree();
  }

  void TearDown() override{
    delete avltree;
  }
};

// 테스트 케이스 정의
TEST_P(SET_AVLTEST, Size){
  for(int key : GetParam()){
    avltree->Insert(key);
  }
  // GetParam().size()는 삽입된 요소의 수와 일치
  ASSERT_EQ(GetParam().size(), avltree->Size());
}

// 테스트에 이용할 데이터 세트를 정의
std::vector<std::vector<int>> testDatasets = {
    {},                 // 비어 있는 트리
    {10},               // 하나의 요소를 삽입
    {10, 20},           // 두 개의 요소를 삽입
    {10, 20, 30},       // 세 개의 요소를 삽입
    {10, 20, 30, 40}    // 네 개의 요소를 삽입
};

// 테스트 데이터를 테스트 케이스에 전달
INSTANTIATE_TEST_SUITE_P(
    Default,
    SET_AVLTEST,
    ::testing::ValuesIn(testDatasets)
);


int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}