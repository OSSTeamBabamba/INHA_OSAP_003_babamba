/*
* avl_tree.cc
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

#include "avl_tree.h"

#include <algorithm>

#include "tree_node.h"
using namespace std;

int AVLTree::getBalance(TreeNode* node) {  // Balance Factor(BF) 계산하는 함수
  if (node == nullptr) return 0;
  int left_node_balanced_factor =
      (node->leftNode() == nullptr) ? -1 : node->leftNode()->height();
  int right_node_balanced_factor =
      (node->rightNode() == nullptr) ? -1 : node->rightNode()->height();
  return left_node_balanced_factor -
         right_node_balanced_factor;  // 좌우 자식 깊이를 비교해 BF 리턴
}

TreeNode* AVLTree::RotateRight(
    TreeNode* z) {  // y는 z의 왼쪽 자식 노드, x는 y의 왼쪽 자식 노드로 설정,
                    // z를 중심으로 오른쪽 회전
  TreeNode* y = z->leftNode();
  TreeNode* T2 = y->rightNode();  // T2는 y의 오른쪽 자식

  // right 회전 수행
  y->setRightNode(z);  // y 노드의 오른쪽 자식 노드를 z노드로 변경
  z->setLeftNode(
      T2);  // z 노드의 왼쪽 자식 노드를 y노드 오른쪽 서브트리(T2)로 변경
  // 위치가 바뀌었으므로 노드 높이 갱신

  // 사이즈 변경
  z->setSize(1 + SubtreeSize(z->leftNode()) + SubtreeSize(z->rightNode()));
  y->setSize(1 + SubtreeSize(y->leftNode()) + SubtreeSize(y->rightNode()));

  int z_left_heigth = (z->leftNode() != nullptr) ? z->leftNode()->height() : -1;
  int z_right_heigth =
      (z->rightNode() != nullptr) ? z->rightNode()->height() : -1;
  z->setHeight(1 + max(z_left_heigth, z_right_heigth));

  int y_left_heigth = (y->leftNode() != nullptr) ? y->leftNode()->height() : -1;
  int y_right_heigth =
      (y->rightNode() != nullptr) ? y->rightNode()->height() : -1;
  y->setHeight(1 + max(y_left_heigth, y_right_heigth));

  // 새로운 루트 노드 y를 반환
  return y;
}

TreeNode* AVLTree::RotateLeft(
    TreeNode* z) {  // y는 z의 오른쪽 자식 노드이고, x는 오른쪽 자식 노드인 경우
                    // z를 중심으로 왼쪽 회전
  TreeNode* y = z->rightNode();
  TreeNode* T2 = y->leftNode();

  // left 회전 수행
  y->setLeftNode(z);  // y노드의 왼쪽 자식 노드를 z노드로 변경
  z->setRightNode(
      T2);  // z노드의 오른쪽 자식 노드를 y노드 왼쪽 서브트리(T2)로 변경

  // 사이즈 변경
  z->setSize(1 + SubtreeSize(z->leftNode()) + SubtreeSize(z->rightNode()));
  y->setSize(1 + SubtreeSize(y->leftNode()) + SubtreeSize(y->rightNode()));

  // 위치가 바뀌었으므로 노드 높이 갱신
  int z_left_heigth = (z->leftNode() != nullptr) ? z->leftNode()->height() : -1;
  int z_right_heigth =
      (z->rightNode() != nullptr) ? z->rightNode()->height() : -1;
  z->setHeight(1 + max(z_left_heigth, z_right_heigth));

  int y_left_heigth = (y->leftNode() != nullptr) ? y->leftNode()->height() : -1;
  int y_right_heigth =
      (y->rightNode() != nullptr) ? y->rightNode()->height() : -1;
  y->setHeight(1 + max(y_left_heigth, y_right_heigth));

  // 새로운 루트 노드 y를 반환
  return y;
}

TreeNode* AVLTree::InsertRecursive(TreeNode* node, int key) {
  if (node == nullptr) {  // 노드가 널포인터 값일 경우 전체 노드의 개수를 1
                          // 증가시키고, TreeNode 생성
    ++total_node_cnt_;
    return new TreeNode(key, nullptr, nullptr, nullptr);
  }
  if (key < node->key()) {
    node->setLeftNode(InsertRecursive(node->leftNode(), key));
  } else if (key > node->key()) {
    node->setRightNode(InsertRecursive(node->rightNode(), key));
  } else {
    return node;
  }

  int left_height =
      (node->leftNode() != nullptr) ? node->leftNode()->height() : -1;
  int right_height =
      (node->rightNode() != nullptr) ? node->rightNode()->height() : -1;

  node->setHeight(1 + max(left_height, right_height));

  int left_size = (node->leftNode() != nullptr) ? node->leftNode()->size() : 0;
  int right_size =
      (node->rightNode() != nullptr) ? node->rightNode()->size() : 0;
  node->setSize(1 + left_size + right_size);

  return Balancing(node, key);
}

TreeNode* AVLTree::Balancing(TreeNode* node,
                             int key) {  // BF를 이용해 회전로직을 구현
  int balance = getBalance(node);        // 노드 밸런스 유지

  // LL (Left Left, right rotation 수행하여 균형을 맞춤)
  if (balance > 1 && key < node->leftNode()->key()) {
    node = RotateRight(node);
  }

  // RR (Right Right, left rotation 수행하여 균형을 맞춤)
  else if (balance < -1 && key > node->rightNode()->key())
    node = RotateLeft(node);

  // LR (Left Right 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
  else if (balance > 1 && key > node->leftNode()->key()) {
    node->setLeftNode(RotateLeft(node->leftNode()));
    node = RotateRight(node);
  }
  // RL (Right, Left 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
  else if (balance < -1 && key < node->rightNode()->key()) {
    node->setRightNode(RotateRight(node->rightNode()));
    node = RotateLeft(node);
  }
  return node;
}

TreeNode* AVLTree::EraseBalancing(TreeNode* node,
                                  int key) {  // BF를 이용해 회전로직을 구현
  int balance = getBalance(node);             // 노드 밸런스 유지

  // LL (Left Left, right rotation 수행하여 균형을 맞춤)
  if (balance > 1 && getBalance(node->leftNode()) >= 0) {
    node = RotateRight(node);
  }

  // RR (Right Right, left rotation 수행하여 균형을 맞춤)
  else if (balance < -1 && getBalance(node->rightNode()) <= 0)
    node = RotateLeft(node);

  // LR (Left Right 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
  else if (balance > 1 && getBalance(node->leftNode()) < 0) {
    node->setLeftNode(RotateLeft(node->leftNode()));
    node = RotateRight(node);
  }
  // RL (Right, Left 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
  else if (balance < -1 && getBalance(node->rightNode()) > 0) {
    node->setRightNode(RotateRight(node->rightNode()));
    node = RotateLeft(node);
  }
  return node;
}

TreeNode* AVLTree::EraseRecursive(TreeNode* node, int key) {
  // 삭제 확인 대상 node가 nullptr 일경우
  if (node == nullptr) {
    return node;
  }
  // 삭제확인 대상 node가 삭제하려는 key보다 클경우 좌측 자식노드으로 이동
  if (key < node->key()) {
    node->setLeftNode(EraseRecursive(node->leftNode(), key));
  }
  // 삭제확인 대상 node가 삭제하려는 key보다 작을경우 우측 자식노드으로 이동
  else if (key > node->key()) {
    node->setRightNode(EraseRecursive(node->rightNode(), key));
  }
  // 삭제확인 대상 node와 일치시
  else {
    // 노드가 한쪽혹은 아예 없을경우
    if (node->leftNode() == nullptr || node->rightNode() == nullptr) {
      // 둘중 하나라도 nullptr일경우 nullptr이 아닌 것을 선택
      TreeNode* temp = node->leftNode() ? node->leftNode() : node->rightNode();

      // 둘다 nullptr일 경우
      if (temp == nullptr) {
        temp = node;
        node = nullptr;
      } else {
        *node = *temp;
      }

      this->total_node_cnt_ -= 1;
      delete temp;
    }
    // 노드가 좌우로 달려있을경우
    else {
      TreeNode* temp = node->rightNode();

      while (temp->leftNode() != nullptr) {
        temp = temp->leftNode();
      }

      node->setKey(temp->key());
      node->setRightNode(EraseRecursive(node->rightNode(), temp->key()));
    }
  }

  if (node == nullptr) {
    return node;
  }

  int left_height =
      (node->leftNode() != nullptr) ? node->leftNode()->height() : -1;
  int right_height =
      (node->rightNode() != nullptr) ? node->rightNode()->height() : -1;
  node->setHeight(1 + max(left_height, right_height));

  int left_size = (node->leftNode() != nullptr) ? node->leftNode()->size() : 0;
  int right_size =
      (node->rightNode() != nullptr) ? node->rightNode()->size() : 0;
  node->setSize(1 + left_size + right_size);

  return EraseBalancing(node, key);
}

int AVLTree::SubtreeSize(TreeNode* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->size();
}

TreeNode* AVLTree::FindNode(int key) {
  TreeNode* current = root_;
  current->setDepth(0);

  while (current != nullptr) {
    int temp = current->depth();  // 현재 노드의 깊이를 저장
    if (key < current->key()) {
      current = current->leftNode();  // 왼쪽 자식 노드로 이동
      if (current != nullptr)
        current->setDepth(temp + 1);  // 현재 노드의 깊이 갱신
    } else if (key > current->key()) {
      current = current->rightNode();  // 오른쪽 자식 노드로 이동
      if (current != nullptr)
        current->setDepth(temp + 1);  // 현재 노드의 깊이 갱신
    } else {
      return current;  // 노드를 찾았을 때 반환
    }
  }
  return nullptr;  // 노드를 찾지 못한 경우 nullptr 반환
}

int AVLTree::RankRecursive(TreeNode* node, int key) {
  if (node == nullptr) {
    return 0;  // 노드가 없으면 0 반환
  }
  // 주어진 키가 현재 노드의 키보다 같거나 클 때
  // 즉, 왼쪽으로는 탐색하지 않아도 된다는 뜻
  if (node->key() <= key) {
    if (node->leftNode() == nullptr) {
      return 1 + RankRecursive(node->rightNode(), key);
    } else {
      // 만약 left노드가 존재하면 insert와 delete에서 이미 구해진 서브트리의
      // 사이즈로 계산.
      return 1 + SubtreeSize(node->leftNode()) +
             RankRecursive(node->rightNode(), key);
    }
  } else {
    return RankRecursive(node->leftNode(), key);
  }
}