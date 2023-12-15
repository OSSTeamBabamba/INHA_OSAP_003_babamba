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