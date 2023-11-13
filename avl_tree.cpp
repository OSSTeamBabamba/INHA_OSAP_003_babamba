#include "avl_tree.h"
#include "avl_node.h"

using namespace std;
int AVLTree::getBalance(AVLNode* node) {
	int leftNodeBalancedFactor = (node->leftNode() == nullptr) ? -1 : node->leftNode()->depth();
	int rightNodeBalancedFactor = (node->rightNode() == nullptr) ? -1 : node->rightNode()->depth();
	if (node == nullptr)
		return 0;
	else
		return abs(leftNodeBalancedFactor - rightNodeBalancedFactor < 2) ? true : false;
}
int AVLTree::insert(int key) {
	// 루트 노드에서 시작하여 새 키를 삽입
	root_ = insertRecursive(root_, key);
	return root_ ? root_->depth() : -1;
	// 루트 노드의 깊이를 반환하거나, 트리가 비어있으면 -1을 반환
}
AVLNode* AVLTree:: insertRecursive(AVLNode* node, int key) {
	if (node == nullptr) {
		++total_node_cnt_; // 새 node를 추가하고, node의 사이즈 1씩 증가
		return new AVLNode(key, nullptr, nullptr, nullptr); // 노드가 없으면 새 노드를 생성하여 반환
	}
	if (key < node->key()) {
		node->setLeftNode(insertRecursive(node->leftNode(), key)); // 키가 현재 노드의 키보다 작으면 왼쪽 서브트리에 삽입
	}
	else if (key > node->key()) {
		node->setRightNode(insertRecursive(node->rightNode(), key)); // 키가 현재 노드의 키보다 크면 오른쪽 서브트리에 삽입
	}
	else {
		return node; // 중복된 키값은 허용하지 않으므로 삽입하지 않음
	}

	// 이 노드의 높이 업데이트
	node->setHeight(1 + max(node->leftNode() ? node->leftNode()->height() : 0,
		node->rightNode() ? node->rightNode()->height() : 0));

	// 이 노드의 밸런스 확인
	int balance = getBalance(node);

	// 회전 로직 구현 (노드 밸런스 깨졌을 경우)
	// LL (Left Left)
	if (balance > 1 && key < node->leftNode()->key()) {
		return rotateRight(node); // LL rotate
	}

	// RR (Right Right)
	if (balance < -1 && key > node->rightNode()->key())
		return rotateLeft(node); // RR rotate

	// LR (Left Right)
	if (balance > 1 && key > node->leftNode()->key()) {
		node->setLeftNode(rotateLeft(node->leftNode())); // 왼쪽 자식을 기준으로 왼쪽 회전 후
		return rotateRight(node); // 현재 노드를 기준으로 오른쪽 회전
	}
	// RL (Right Left)
	if (balance < -1 && key < node->rightNode()->key()) {
		node->setRightNode(rotateRight(node->rightNode())); // 오른쪽 자식 기준으로 오른쪽 회전 후
		return rotateLeft(node); // 현재 노드 기준으로 왼쪽 회전 수행
	}
	return node; // 변경되지 않은 노드 포인터 리턴
}
int AVLTree::erase(int key) {
	return NULL;
}
bool AVLTree::empty() {
	return root_ == nullptr;
}
int AVLTree::size() {
	return total_node_cnt_;
}
int AVLTree::find(int key) {
	return NULL;
}
AVLNode* AVLTree::findNode(int key) {
	return NULL;
}
int AVLTree::minimum(int key) {
	return NULL;
}
int AVLTree::maximum(int key) {
	return NULL;
}
int AVLTree::rank(int key) {
	return NULL;
}
// node를 기준으로 오른쪽으로 회전
AVLNode AVLTree:: rotateRight(AVLNode* y) { // node를 기준으로 오른쪽으로 회전하는 메서드
	AVLNode* x = y->leftNode(); // y의 오른쪽 자식을 x로 설정
	AVLNode* z = x->rightNode(); // x의 오른쪽 자식을 z로 설정

	// 회전 수행
	x->setRightNode(y); // x의 오른쪽 자식을 y로 설정
	y->setLeftNode(z); // y의 왼쪽 자식을 z로 설정

	// 높이 업데이트
	// y의 왼쪽 및 오른쪽 자식 중 더 높은 키값을 가진 자식의 높이를 찾아 y의 높이를 설정
	int yLeftHeight = y->leftNode() ? y->leftNode()->height() : 0; // y의 왼쪽 자식의 높이
	int yRightHeight = y->rightNode() ? y->rightNode()->height() : 0; // y의 오른쪽 자식의 높이
	y->setHeight((yLeftHeight > yRightHeight ? yLeftHeight : yRightHeight) + 1); // 더 높은 높이에 1을 더해 높이를 업데이트

	// x의 왼쪽 및 오른쪽 자식 중 더 높은 자식의 높이를 찾아 x의 높이를 설정
	int xLeftHeight = x->leftNode() ? x->leftNode()->height() : 0; // x의 왼쪽 자식의 높이
	int xRightHeight = x->rightNode() ? x->rightNode()->height() : 0; // x의 오른쪽 자식의 높이
	x->setHeight((xLeftHeight > xRightHeight ? xLeftHeight : xRightHeight) + 1); // 더 높은 높이에 1을 더해 x의 높이를 업데이트

	// 새로운 루트 노드 리턴
	return x;
}
// node를 기준으로 왼쪽으로 회전
AVLNode AVLTree:: rotateLeft(AVLNode* x) {
	AVLNode* y = x->rightNode(); // x의 오른쪽 자식을 y로 설정
	AVLNode* z = y->leftNode(); // y의 왼쪽 자식을 z로 설정

	// 회전 수행
	y->setLeftNode(x); // y의 왼쪽 자식을 x로 설정
	x->setRightNode(z); // x의 오른쪽 자식을 z로 설정

	// 높이 업데이트
	// x의 왼쪽 및 오른쪽 자식 중 더 높은 자식의 높이를 찾아 x의 높이를 설정
	int xLeftHeight = x->leftNode() ? x->leftNode()->height() : 0; // x의 왼쪽 자식의 높이
	int xRightHeight = x->rightNode() ? x->rightNode()->height() : 0; // x의 오른쪽 자식의 높이
	x->setHeight((xLeftHeight > xRightHeight ? xLeftHeight : xRightHeight) + 1); // 더 높은 높이에 1을 더해 x의 높이를 업데이트

	// y의 왼쪽 및 오른쪽 자식 중 더 높은 자식의 높이를 찾아 y의 높이를 설정
	int yLeftHeight = y->leftNode() ? y->leftNode() ? y->leftNode()->height() : 0; // y의 왼쪽 자식의 높이
	int rRightHeight = y->rightNode() ? y->rightNode()->height() : 0; // y의 오른쪽 자식의 높이
	y->setHeight((yLeftHeight > xRightHeight ? yLeftHeight : xRightHeight) + 1); // 더 높은 높이에 1을 더해 y의 높이를 업데이트
	return y; // 새로운 루트 노드인 y를 반환
}