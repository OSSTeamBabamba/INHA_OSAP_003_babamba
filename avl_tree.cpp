#include "avl_tree.h"
#include "tree_node.h"
#include<algorithm>
using namespace std;

int AVLTree::getBalance(TreeNode* node) { // Balance Factor(BF) 계산하는 함수
    if (node == nullptr)
        return 0;
    int leftNodeBalancedFactor = (node->leftNode() == nullptr) ? -1 : node->leftNode()->height();
    int rightNodeBalancedFactor = (node->rightNode() == nullptr) ? -1 : node->rightNode()->height();
    return leftNodeBalancedFactor - rightNodeBalancedFactor; // 좌우 자식 깊이를 비교해 BF 리턴
}

TreeNode* AVLTree:: rotateRight(TreeNode* z) { // y는 z의 왼쪽 자식 노드, x는 y의 왼쪽 자식 노드로 설정, z를 중심으로 오른쪽 회전
    TreeNode *y = z->leftNode();
    TreeNode *T2 = y->rightNode(); // T2는 y의 오른쪽 자식

    // right 회전 수행
    y->setRightNode(z);// y 노드의 오른쪽 자식 노드를 z노드로 변경
    z->setLeftNode(T2); // z 노드의 왼쪽 자식 노드를 y노드 오른쪽 서브트리(T2)로 변경
    // 위치가 바뀌었으므로 노드 높이 갱신

    int zLeftHeight = (z->leftNode() != nullptr) ? z->leftNode()->height() : 0;
    int zRightHeight = (z->rightNode() != nullptr) ? z->rightNode()->height() : 0;

    int yLeftHeight = (y->leftNode() != nullptr) ? y->leftNode()->height() : 0;
    int yRightHeight = (y->rightNode() != nullptr) ? y->rightNode()->height() : 0;

    z->setHeight(1 + max(zLeftHeight, zRightHeight));
    y->setHeight(1 + max(yLeftHeight, yRightHeight));

    // 새로운 루트 노드 y를 반환
    return y;
}

TreeNode* AVLTree:: rotateLeft(TreeNode* z) { // y는 z의 오른쪽 자식 노드이고, x는 오른쪽 자식 노드인 경우 z를 중심으로 왼쪽 회전
    TreeNode *y = z->rightNode();
    TreeNode *T2 = y->leftNode();

    // left 회전 수행
    y->setLeftNode(z); // y노드의 왼쪽 자식 노드를 z노드로 변경
    z->setRightNode(T2); // z노드의 오른쪽 자식 노드를 y노드 왼쪽 서브트리(T2)로 변경

    // 위치가 바뀌었으므로 노드 높이 갱신
    int zLeftHeight = (z->leftNode() != nullptr) ? z->leftNode()->height() : 0;
    int zRightHeight = (z->rightNode() != nullptr) ? z->rightNode()->height() : 0;

    int yLeftHeight = (y->leftNode() != nullptr) ? y->leftNode()->height() : 0;
    int yRightHeight = (y->rightNode() != nullptr) ? y->rightNode()->height() : 0;

    z->setHeight(1 + max(zLeftHeight, zRightHeight));
    y->setHeight(1 + max(yLeftHeight, yRightHeight));

    // 새로운 루트 노드 y를 반환
    return y;
}

int AVLTree::insert(int key) {

    root_ = insertRecursive(root_, key);
    return root_ ? root_->height() : -1;

}
TreeNode* AVLTree:: insertRecursive(TreeNode* node, int key) {
    if (node == nullptr) {
        ++total_node_cnt_;
        return new TreeNode(key, nullptr, nullptr, nullptr);
    }
    if (key < node->key()) {
        node->setLeftNode(insertRecursive(node->leftNode(), key));
    }
    else if (key > node->key()) {
        node->setRightNode(insertRecursive(node->rightNode(), key));
    }
    else {
        return node;
    }

    int leftHeight = (node->leftNode() != nullptr) ? node->leftNode()->height() : 0;
    int rightHeight = (node->rightNode() != nullptr) ? node->rightNode()->height() : 0;
    node->setHeight(1 + max(leftHeight, rightHeight));

    int balance = getBalance(node); // 노드 밸런스 유지

    // LL (Left Left, right rotation 수행하여 균형을 맞춤)
    if (balance > 1 && key < node->leftNode()->key()) {
        return rotateRight(node); // LL rotate
    }

    // RR (Right Right, left rotation 수행하여 균형을 맞춤)
    if (balance < -1 && key > node->rightNode()->key())
        return rotateLeft(node); // RR rotate

    // LR (Left Right 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
    if (balance > 1 && key > node->leftNode()->key()) {
        node->setLeftNode(rotateLeft(node->leftNode()));
        return rotateRight(node);
    }
    // RL (Right, Left 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
    if (balance < -1 && key < node->rightNode()->key()) {
        node->setRightNode(rotateRight(node->rightNode()));
        return rotateLeft(node);
    }
    return node;
}
int AVLTree::erase(int key) {
  if(eraseRecursive(root_,key)==nullptr)
    return -1;
  else{
    return 0;
  }
}

TreeNode* AVLTree::eraseRecursive(TreeNode* node, int key){
//삭제 확인 대상 node가 nullptr 일경우
  if(node== nullptr){
    return node;
  }
// 삭제확인 대상 node가 삭제하려는 key보다 클경우 좌측 자식노드으로 이동
  if(key < node->key()){
    node->setLeftNode(eraseRecursive(node->leftNode(),key));
  }
  // 삭제확인 대상 node가 삭제하려는 key보다 작을경우 우측 자식노드으로 이동
  else if(key > node->key()){
    node->setRightNode(eraseRecursive(node->rightNode(),key));
  }
  // 삭제확인 대상 node와 일치시
  else{
    //노드가 한쪽혹은 아예 없을경우
    if(node->leftNode() == nullptr ||
        node->rightNode() == nullptr){

      //둘중 하나라도 nullptr일경우 nullptr이 아닌 것을 선택
      TreeNode* temp = node->leftNode() ? node->leftNode() : node->rightNode();

      //둘다 nullptr일 경우
      if(temp == nullptr){
        temp = node;
        node = nullptr;
      }
      else{
        *node = *temp;
      }

      delete temp;
    }
    //노드가 좌우로 달려있을경우
    else{

      TreeNode* temp = node->rightNode();

      while (temp->leftNode() != nullptr) {
        temp = temp->leftNode();
      }

      node->setKey(temp->key());
      node->setRightNode(eraseRecursive(node->rightNode(),temp->key()));

    }
  }

  if (node == nullptr){
    return node;
  }

  //TODO: insert 함수와 중복됨 해당 기능 함수와 필요가 있음
  // 트리 안정화 작업

  int leftHeight = (node->leftNode() != nullptr) ? node->leftNode()->height() : 0;
  int rightHeight = (node->rightNode() != nullptr) ? node->rightNode()->height() : 0;
  node->setHeight(1 + max(leftHeight, rightHeight));

  int balance = getBalance(node); // 노드 밸런스 유지

  // LL (Left Left, right rotation 수행하여 균형을 맞춤)
  if (balance > 1 && key < node->leftNode()->key()) {
    return rotateRight(node); // LL rotate
  }

  // RR (Right Right, left rotation 수행하여 균형을 맞춤)
  if (balance < -1 && key > node->rightNode()->key())
    return rotateLeft(node); // RR rotate

  // LR (Left Right 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
  if (balance > 1 && key > node->leftNode()->key()) {
    node->setLeftNode(rotateLeft(node->leftNode()));
    return rotateRight(node);
  }
  // RL (Right, Left 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
  if (balance < -1 && key < node->rightNode()->key()) {
    node->setRightNode(rotateRight(node->rightNode()));
    return rotateLeft(node);
  }

  return node;

}

bool AVLTree::empty() {
    return root_ == nullptr;
}
int AVLTree::size() {
    return total_node_cnt_;
}
int AVLTree::find(int key) {
    return 0;
}
TreeNode* AVLTree::findNode(int key) {
    return NULL;
}

pair<int,int> AVLTree::minimum(int key)  {
    return {0,0};
}
pair<int,int> AVLTree::maximum(int key) {
    return {0,0};
}
int AVLTree::rank(int key) {
    return 0;
}

//TODO: 테스트 이후 제거될 기능
void AVLTree::inorderTraversal(TreeNode* node){
    if(node == nullptr) return;
    inorderTraversal(node->leftNode());

    cout<<node->key()<<" ";

    inorderTraversal(node->rightNode());
}