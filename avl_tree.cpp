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

TreeNode* AVLTree:: RotateRight(TreeNode* z) { // y는 z의 왼쪽 자식 노드, x는 y의 왼쪽 자식 노드로 설정, z를 중심으로 오른쪽 회전
    TreeNode *y = z->leftNode();
    TreeNode *T2 = y->rightNode(); // T2는 y의 오른쪽 자식

    // right 회전 수행
    y->setRightNode(z);// y 노드의 오른쪽 자식 노드를 z노드로 변경
    z->setLeftNode(T2); // z 노드의 왼쪽 자식 노드를 y노드 오른쪽 서브트리(T2)로 변경
    // 위치가 바뀌었으므로 노드 높이 갱신

    //사이즈 변경
    z->setSize(1 + SubtreeSize(z->leftNode()) + SubtreeSize(z->rightNode()));
    y->setSize(1 + SubtreeSize(y->leftNode()) + SubtreeSize(y->rightNode()));


    int zLeftHeight = (z->leftNode() != nullptr) ? z->leftNode()->height() : -1;
    int zRightHeight = (z->rightNode() != nullptr) ? z->rightNode()->height() : -1;
    z->setHeight(1 + max(zLeftHeight, zRightHeight));

    int yLeftHeight = (y->leftNode() != nullptr) ? y->leftNode()->height() : -1;
    int yRightHeight = (y->rightNode() != nullptr) ? y->rightNode()->height() : -1;
    y->setHeight(1 + max(yLeftHeight, yRightHeight));

    // 새로운 루트 노드 y를 반환
    return y;
}

TreeNode* AVLTree:: RotateLeft(TreeNode* z) { // y는 z의 오른쪽 자식 노드이고, x는 오른쪽 자식 노드인 경우 z를 중심으로 왼쪽 회전
    TreeNode *y = z->rightNode();
    TreeNode *T2 = y->leftNode();

    // left 회전 수행
    y->setLeftNode(z); // y노드의 왼쪽 자식 노드를 z노드로 변경
    z->setRightNode(T2); // z노드의 오른쪽 자식 노드를 y노드 왼쪽 서브트리(T2)로 변경

    //사이즈 변경
    z->setSize(1 + SubtreeSize(z->leftNode()) + SubtreeSize(z->rightNode()));
    y->setSize(1 + SubtreeSize(y->leftNode()) + SubtreeSize(y->rightNode()));


    // 위치가 바뀌었으므로 노드 높이 갱신
    int zLeftHeight = (z->leftNode() != nullptr) ? z->leftNode()->height() : -1;
    int zRightHeight = (z->rightNode() != nullptr) ? z->rightNode()->height() : -1;
    z->setHeight(1 + max(zLeftHeight, zRightHeight));

    int yLeftHeight = (y->leftNode() != nullptr) ? y->leftNode()->height() : -1;
    int yRightHeight = (y->rightNode() != nullptr) ? y->rightNode()->height() : -1;
    y->setHeight(1 + max(yLeftHeight, yRightHeight));

    // 새로운 루트 노드 y를 반환
    return y;
}

int AVLTree::Insert(int key) {

    root_ = InsertRecursive(root_, key); // 루트에서부터 시작해 재귀적으로 키 값 삽입
    return Find(key);

}
TreeNode* AVLTree:: InsertRecursive(TreeNode* node, int key) {
    if (node == nullptr) { // 노드가 널포인터 값일 경우 전체 노드의 개수를 1 증가시키고, TreeNode 생성
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

    int leftHeight = (node->leftNode() != nullptr) ? node->leftNode()->height() : -1;
    int rightHeight = (node->rightNode() != nullptr) ? node->rightNode()->height() : -1;

    node->setHeight(1 + max(leftHeight, rightHeight));

    int leftSize = (node->leftNode() != nullptr) ? node->leftNode()->size() : 0;
    int rightSize = (node->rightNode() != nullptr) ? node->rightNode()->size() : 0;
    node->setSize(1 + leftSize + rightSize);

    return Balancing(node, key);
}

TreeNode* AVLTree::Balancing(TreeNode* node, int key) { // BF를 이용해 회전로직을 구현
    int balance = getBalance(node); // 노드 밸런스 유지

    // LL (Left Left, right rotation 수행하여 균형을 맞춤)
    if (balance > 1 && key < node->leftNode()->key()) {
        node = RotateRight(node);
    }

    // RR (Right Right, left rotation 수행하여 균형을 맞춤)
    if (balance < -1 && key > node->rightNode()->key())
        node = RotateLeft(node);

    // LR (Left Right 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
    if (balance > 1 && key > node->leftNode()->key()) {
        node->setLeftNode(RotateLeft(node->leftNode()));
        node =  RotateRight(node);
    }
    // RL (Right, Left 순으로 총 두번의 rotation 수행하여 균형을 맞춤)
    if (balance < -1 && key < node->rightNode()->key()) {
        node->setRightNode(RotateRight(node->rightNode()));
        node= RotateLeft(node);
    }
    return node;
}
int AVLTree::Erase(int key) {

  TreeNode* targetNode = FindNode(key);
  if(targetNode == nullptr){
    return 0;
  }else{
    int target_depth = targetNode->depth();
    EraseRecursive(root_,key);
    return target_depth;
  }

}

TreeNode* AVLTree::EraseRecursive(TreeNode* node, int key){
//삭제 확인 대상 node가 nullptr 일경우
  if(node== nullptr){
    return node;
  }
// 삭제확인 대상 node가 삭제하려는 key보다 클경우 좌측 자식노드으로 이동
  if(key < node->key()){
    node->setLeftNode(EraseRecursive(node->leftNode(),key));
  }
  // 삭제확인 대상 node가 삭제하려는 key보다 작을경우 우측 자식노드으로 이동
  else if(key > node->key()){
    node->setRightNode(EraseRecursive(node->rightNode(),key));
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
        this->total_node_cnt_ -= 1;
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
      node->setRightNode(EraseRecursive(node->rightNode(),temp->key()));

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

  int leftSize = (node->leftNode() != nullptr) ? node->leftNode()->size() : 0;
  int rightSize = (node->rightNode() != nullptr) ? node->rightNode()->size() : 0;
  node->setSize(1 + leftSize + rightSize);

  return Balancing(node,key);

}

bool AVLTree::Empty() {
    return root_ == nullptr;
}
int AVLTree::Size() {
    return total_node_cnt_;
}

int AVLTree::SubtreeSize(TreeNode* node) {
    if(node == nullptr){
        return 0;
    }
    return node->size();
}


int AVLTree::Find(int key) {
    TreeNode* node = FindNode(key);
    if (node != nullptr)
        return node->depth();
    else
        return -1;
}

TreeNode* AVLTree::FindNode(int key) {
    TreeNode* current = root_;
    current->setDepth(0);

    while (current != nullptr) {
        int temp = current->depth(); // 현재 노드의 깊이를 저장
        if (key < current->key()) {
            current = current->leftNode(); // 왼쪽 자식 노드로 이동
            if (current != nullptr)
                current->setDepth(temp + 1); // 현재 노드의 깊이 갱신
        } else if (key > current->key()) {
            current = current->rightNode(); // 오른쪽 자식 노드로 이동
            if (current != nullptr)
                current->setDepth(temp + 1); // 현재 노드의 깊이 갱신
        } else {
            return current; // 노드를 찾았을 때 반환
        }
    }
    return nullptr; // 노드를 찾지 못한 경우 nullptr 반환
}

pair<int,int> AVLTree::Minimum(int key)  {
    //주어진 key를 가진 노드를 찾습니다.
    TreeNode* curNode = FindNode(key);

    //만약 할당된 노드가 nullptr 이라면 해당 키를 가진 노드가 없다는 뜻이므로
    //에러의 의미인 -1을 반환합니다.
    //조건에 부합하는 테스트케이스라면 이 코드는 작동하지 않음.
    if(curNode == nullptr) return {-1,-1};

    //왼쪽 자식이 nullptr일 때까지 왼쪽 자식 노드를 curNode로 update합니다.
    while (curNode->leftNode() != nullptr) {
        curNode = curNode->leftNode();
    }
    //값 리턴
    return {curNode->depth(), curNode->key()};
}

pair<int,int> AVLTree::Maximum(int key) {
    return {0,0};
}
pair<int,int> AVLTree::Rank(int key) {
    return {Find(key), RankRecursive(root_, key)};
}

int AVLTree::RankRecursive(TreeNode* node, int key) {
    if (node == nullptr) {
        return 0; // 노드가 없으면 0 반환
    }
    //주어진 키가 현재 노드의 키보다 같거나 클 때
    //즉, 왼쪽으로는 탐색하지 않아도 된다는 뜻
    if(node->key() <= key){
        if(node->leftNode() == nullptr){
            return 1 + RankRecursive(node->rightNode(),key);
        }
        else{
            //만약 left노드가 존재하면 insert와 delete에서 이미 구해진 서브트리의 사이즈로 계산.
            return 1 + SubtreeSize(node->leftNode()) + RankRecursive(node->rightNode(), key);
        }
    }
    else{
        return RankRecursive(node->leftNode(), key);
    }
}


void AVLTree::InorderTraversal(TreeNode* node){ // 왼쪽 자식 -> 루트 -> 오른쪽 자식 순으로 중위순회 수행
    if(node == nullptr) return;
    InorderTraversal(node->leftNode());

    cout<<node->key()<<" ";

    InorderTraversal(node->rightNode());
}