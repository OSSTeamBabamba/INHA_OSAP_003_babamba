#include "avl_tree.h"
#include "tree_node.h"
#include "tree.h"
#include<algorithm>
using namespace std;

int AVLTree::getBalance(TreeNode* node) { // Balance Factor(BF) 계산하는 함수
    if (node == nullptr)
        return 0;
	int leftNodeBalancedFactor = (node->leftNode() == nullptr) ? -1 : node->leftNode()->depth();
	int rightNodeBalancedFactor = (node->rightNode() == nullptr) ? -1 : node->rightNode()->depth();
    return leftNodeBalancedFactor - rightNodeBalancedFactor; // 좌우 자식 깊이를 비교해 BF 리턴
}

TreeNode* AVLTree:: rotateRight(TreeNode* z) { // y는 z의 왼쪽 자식 노드, x는 y의 왼쪽 자식 노드로 설정, z를 중심으로 오른쪽 회전
    TreeNode *y = z->leftNode();
    TreeNode *T2 = y->rightNode(); // T2는 y의 오른쪽 자식

    // right 회전 수행
    y->setRightNode(z);// y 노드의 오른쪽 자식 노드를 z노드로 변경
    z->setLeftNode(T2); // z 노드의 왼쪽 자식 노드를 y노드 오른쪽 서브트리(T2)로 변경
    // 위치가 바뀌었으므로 노드 높이 갱신
    z->setHeight(1 + max(z->leftNode()->height(), z->rightNode()->height()));
    y->setHeight(1 + max(y->leftNode()->height(), y->rightNode()->height()));

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
    z->setHeight(1 + max(z->leftNode()->height(), z->rightNode()->height()));
    y->setHeight(1 + max(y->leftNode()->height(), y->rightNode()->height()));

    // 새로운 루트 노드 y를 반환
    return y;
}

int AVLTree::insert(int key) {

	root_ = insertRecursive(root_, key);
	return root_ ? root_->depth() : -1;

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

	node->setHeight(1 + max(node->leftNode()->height(), node->rightNode()->height())); // 노드 높이 갱신
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

