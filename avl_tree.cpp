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
    return 0;
}
bool AVLTree::empty() {
    return root_ == nullptr;
}
int AVLTree::size() {
    return total_node_cnt_;
}
int AVLTree::find(int key) {
    TreeNode* node = findNode(key);
    if (node != nullptr)
        return node->depth();
    else
        return -1;
}

TreeNode* AVLTree::findNode(int key) {
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


pair<int,int> AVLTree::minimum(int key)  {
    return {0,0};
}
pair<int,int> AVLTree::maximum(int key) {
    return {0,0};
}
int AVLTree::rank(int key) {
    return rankRecursive(root_, key);
}

int AVLTree::rankRecursive(TreeNode* node, int key) {
    if (node == nullptr) {
        return 0; // 노드가 없으면 0 반환
    }

    int leftCount = rankRecursive(node->leftNode(), key); // 왼쪽 서브트리의 랭크 계산
    int rightCount = rankRecursive(node->rightNode(), key); // 오른쪽 서브트리의 랭크 계산

    if (key >= node->key()) {
        // 현재 노드의 키가 주어진 키보다 작거나 같으면
        // 왼쪽 서브트리의 랭크, 오른쪽 서브트리의 랭크, 현재 노드를 포함한 1을 더한 값을 반환
        return leftCount + rightCount + 1;
    } else {
        // 현재 노드의 키가 주어진 키보다 크면
        // 왼쪽 서브트리의 랭크를 반환
        return leftCount;
    }
}


void AVLTree::inorderTraversal(TreeNode* node){
    if(node == nullptr) return;
    inorderTraversal(node->leftNode());

    cout<<node->key()<<" ";

    inorderTraversal(node->rightNode());
}