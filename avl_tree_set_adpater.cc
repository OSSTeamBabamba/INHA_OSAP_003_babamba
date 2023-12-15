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

#include "avl_tree_set_adapter.h"
#include "avl_tree.h"
#include "tree_node.h"
#include<algorithm>

int AVLTreeSetAdapter::Erase(int key) {

  TreeNode* targetNode = FindNode(key);
  if(targetNode == nullptr){
    return 0;
  }else{
    int target_depth = targetNode->depth();
    root_ = EraseRecursive(root_,key);
    return target_depth;
  }
}


int AVLTreeSetAdapter::Insert(int key) {
  root_ = InsertRecursive(root_, key); // 루트에서부터 시작해 재귀적으로 키 값 삽입
  return Find(key);
}


bool AVLTreeSetAdapter::Empty() {
  return root_ == nullptr;
}
int AVLTreeSetAdapter::Size() {
  return total_node_cnt_;
}


pair<int,int> AVLTreeSetAdapter::Minimum(int key)  {
  //주어진 key를 가진 노드를 찾습니다.
  TreeNode* cur_node = FindNode(key);

  //만약 할당된 노드가 nullptr 이라면 해당 키를 가진 노드가 없다는 뜻이므로
  //에러의 의미인 -1을 반환합니다.
  //조건에 부합하는 테스트케이스라면 이 코드는 작동하지 않음.
  if(cur_node == nullptr) return {-1,-1};

  //왼쪽 자식이 nullptr일 때까지 왼쪽 자식 노드를 curNode로 update합니다.
  while (cur_node->leftNode() != nullptr) {
    cur_node = cur_node->leftNode();
  }
  //값 리턴
  return {Find(cur_node->key()), cur_node->key()};
}

pair<int,int> AVLTreeSetAdapter::Maximum(int key) {
  //주어진 key를 가진 노드를 찾습니다.
  TreeNode* cur_node = FindNode(key);

  //만약 할당된 노드가 nullptr 이라면 해당 키를 가진 노드가 없다는 뜻이므로
  //에러의 의미인 -1을 반환합니다.
  //조건에 부합하는 테스트케이스라면 이 코드는 작동하지 않음.
  if(cur_node == nullptr) return {-1,-1};

  //왼쪽 자식이 nullptr일 때까지 왼쪽 자식 노드를 curNode로 update합니다.
  while (cur_node->rightNode() != nullptr) {
    cur_node = cur_node->rightNode();
  }
  //값 리턴
  return {Find(cur_node->key()), cur_node->key()};
}
pair<int,int> AVLTreeSetAdapter::Rank(int key) {
  return {Find(key), RankRecursive(root_, key)};
}

int AVLTreeSetAdapter::Find(int key) {
  TreeNode* node = FindNode(key);
  if (node != nullptr)
    return node->depth();
  else
    return -1;
}