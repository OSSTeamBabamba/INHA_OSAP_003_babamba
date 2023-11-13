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
	// ��Ʈ ��忡�� �����Ͽ� �� Ű�� ����
	root_ = insertRecursive(root_, key);
	return root_ ? root_->depth() : -1;
	// ��Ʈ ����� ���̸� ��ȯ�ϰų�, Ʈ���� ��������� -1�� ��ȯ
}
AVLNode* AVLTree:: insertRecursive(AVLNode* node, int key) {
	if (node == nullptr) {
		++total_node_cnt_; // �� node�� �߰��ϰ�, node�� ������ 1�� ����
		return new AVLNode(key, nullptr, nullptr, nullptr); // ��尡 ������ �� ��带 �����Ͽ� ��ȯ
	}
	if (key < node->key()) {
		node->setLeftNode(insertRecursive(node->leftNode(), key)); // Ű�� ���� ����� Ű���� ������ ���� ����Ʈ���� ����
	}
	else if (key > node->key()) {
		node->setRightNode(insertRecursive(node->rightNode(), key)); // Ű�� ���� ����� Ű���� ũ�� ������ ����Ʈ���� ����
	}
	else {
		return node; // �ߺ��� Ű���� ������� �����Ƿ� �������� ����
	}

	// �� ����� ���� ������Ʈ
	node->setHeight(1 + max(node->leftNode() ? node->leftNode()->height() : 0,
		node->rightNode() ? node->rightNode()->height() : 0));

	// �� ����� �뷱�� Ȯ��
	int balance = getBalance(node);

	// ȸ�� ���� ���� (��� �뷱�� ������ ���)
	// LL (Left Left)
	if (balance > 1 && key < node->leftNode()->key()) {
		return rotateRight(node); // LL rotate
	}

	// RR (Right Right)
	if (balance < -1 && key > node->rightNode()->key())
		return rotateLeft(node); // RR rotate

	// LR (Left Right)
	if (balance > 1 && key > node->leftNode()->key()) {
		node->setLeftNode(rotateLeft(node->leftNode())); // ���� �ڽ��� �������� ���� ȸ�� ��
		return rotateRight(node); // ���� ��带 �������� ������ ȸ��
	}
	// RL (Right Left)
	if (balance < -1 && key < node->rightNode()->key()) {
		node->setRightNode(rotateRight(node->rightNode())); // ������ �ڽ� �������� ������ ȸ�� ��
		return rotateLeft(node); // ���� ��� �������� ���� ȸ�� ����
	}
	return node; // ������� ���� ��� ������ ����
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
// node�� �������� ���������� ȸ��
AVLNode AVLTree:: rotateRight(AVLNode* y) { // node�� �������� ���������� ȸ���ϴ� �޼���
	AVLNode* x = y->leftNode(); // y�� ������ �ڽ��� x�� ����
	AVLNode* z = x->rightNode(); // x�� ������ �ڽ��� z�� ����

	// ȸ�� ����
	x->setRightNode(y); // x�� ������ �ڽ��� y�� ����
	y->setLeftNode(z); // y�� ���� �ڽ��� z�� ����

	// ���� ������Ʈ
	// y�� ���� �� ������ �ڽ� �� �� ���� Ű���� ���� �ڽ��� ���̸� ã�� y�� ���̸� ����
	int yLeftHeight = y->leftNode() ? y->leftNode()->height() : 0; // y�� ���� �ڽ��� ����
	int yRightHeight = y->rightNode() ? y->rightNode()->height() : 0; // y�� ������ �ڽ��� ����
	y->setHeight((yLeftHeight > yRightHeight ? yLeftHeight : yRightHeight) + 1); // �� ���� ���̿� 1�� ���� ���̸� ������Ʈ

	// x�� ���� �� ������ �ڽ� �� �� ���� �ڽ��� ���̸� ã�� x�� ���̸� ����
	int xLeftHeight = x->leftNode() ? x->leftNode()->height() : 0; // x�� ���� �ڽ��� ����
	int xRightHeight = x->rightNode() ? x->rightNode()->height() : 0; // x�� ������ �ڽ��� ����
	x->setHeight((xLeftHeight > xRightHeight ? xLeftHeight : xRightHeight) + 1); // �� ���� ���̿� 1�� ���� x�� ���̸� ������Ʈ

	// ���ο� ��Ʈ ��� ����
	return x;
}
// node�� �������� �������� ȸ��
AVLNode AVLTree:: rotateLeft(AVLNode* x) {
	AVLNode* y = x->rightNode(); // x�� ������ �ڽ��� y�� ����
	AVLNode* z = y->leftNode(); // y�� ���� �ڽ��� z�� ����

	// ȸ�� ����
	y->setLeftNode(x); // y�� ���� �ڽ��� x�� ����
	x->setRightNode(z); // x�� ������ �ڽ��� z�� ����

	// ���� ������Ʈ
	// x�� ���� �� ������ �ڽ� �� �� ���� �ڽ��� ���̸� ã�� x�� ���̸� ����
	int xLeftHeight = x->leftNode() ? x->leftNode()->height() : 0; // x�� ���� �ڽ��� ����
	int xRightHeight = x->rightNode() ? x->rightNode()->height() : 0; // x�� ������ �ڽ��� ����
	x->setHeight((xLeftHeight > xRightHeight ? xLeftHeight : xRightHeight) + 1); // �� ���� ���̿� 1�� ���� x�� ���̸� ������Ʈ

	// y�� ���� �� ������ �ڽ� �� �� ���� �ڽ��� ���̸� ã�� y�� ���̸� ����
	int yLeftHeight = y->leftNode() ? y->leftNode() ? y->leftNode()->height() : 0; // y�� ���� �ڽ��� ����
	int rRightHeight = y->rightNode() ? y->rightNode()->height() : 0; // y�� ������ �ڽ��� ����
	y->setHeight((yLeftHeight > xRightHeight ? yLeftHeight : xRightHeight) + 1); // �� ���� ���̿� 1�� ���� y�� ���̸� ������Ʈ
	return y; // ���ο� ��Ʈ ����� y�� ��ȯ
}