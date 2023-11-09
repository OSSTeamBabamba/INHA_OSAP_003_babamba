#include "avl_node.h"

int32_t AVLNode::key() const {
    return key_;
}
void AVLNode::setKey(int32_t key) {
    key_ = key;
}
int32_t AVLNode::depth() const {
    return depth_;
}
void AVLNode::setDepth(int32_t depth) {
    depth_ = depth;
}
int32_t AVLNode::height() const {
    return height_;
}
void AVLNode::setHeight(int32_t height) {
    height_ = height;
}

AVLNode *AVLNode::parentNode() const {
    return parentNode_;
}
void AVLNode::setParentNode(AVLNode *leftNode) {
    parentNode_ = leftNode;
}

AVLNode *AVLNode::leftNode() const {
    return leftNode_;
}
void AVLNode::setLeftNode(AVLNode *leftNode) {
    leftNode_ = leftNode;
}
AVLNode *AVLNode::rightNode() const {
    return rightNode_;
}
void AVLNode::setRightNode(AVLNode *rightNode) {
    rightNode_ = rightNode;
}
