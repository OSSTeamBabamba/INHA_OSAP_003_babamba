#include "avl_tree.h"

#include <algorithm>
#include <cmath>

#include "avl_node.h"

using namespace std;

bool AVLTree::isBalanced(AVLNode *node) {
  int leftNodeBalancedFactor =
      (node->leftNode() == nullptr) ? -1 : node->leftNode()->depth();
  int rightNodeBalancedFactor =
      (node->rightNode() == nullptr) ? -1 : node->rightNode()->depth();

  return abs(leftNodeBalancedFactor - rightNodeBalancedFactor < 2) ? true
                                                                   : false;
}

int AVLTree::insert(int key) { return NULL; }

int AVLTree::erase(int key) {
    return NULL;
}

bool AVLTree::empty() {
    return NULL;
}
int AVLTree::size() {
    return NULL;
}

int AVLTree::find(int key) { return NULL; }
AVLNode *AVLTree::findNode(int key) { return NULL; }

pair<int, int> AVLTree::minimum(int key) { return NULL; }

pair<int, int> AVLTree::maximum(int key) {
  AVLNode *node = findNode(key);

  if(!node){ // 해당 key를 못 찾을 시 함수 종료;
    return make_pair(-1,-1);
  }

  while (node->rightNode() != nullptr) { // 해당 노드에서 계속 큰값을 향해 이동 이후 해당 노드보다 큰값이 없으면 이동 종료
    node = node->rightNode();
  }
  return make_pair(node->key(), node->depth()); // 해당 노드의 key와 depth 반환
}

int AVLTree::rank(int key) { return NULL; }
AVLNode AVLTree::*rotateRight(AVLNode *node) { return NULL; }
AVLNode AVLTree::*rotateLeft(AVLNode *node) { return NULL; }