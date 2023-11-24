#include "tree_node.h"
using namespace std;

int32_t TreeNode::depth() const {
    return depth_;
}
void TreeNode::setDepth(int32_t depth) {
    depth_ = depth;
}
int32_t TreeNode::height() const {
    return height_;
}
void TreeNode::setHeight(int32_t height) {
    height_ = height;
}

TreeNode* TreeNode::parentNode() const {
    return parentNode_;
}
void TreeNode::setParentNode(TreeNode* leftNode) {
    parentNode_ = leftNode;
}

TreeNode* TreeNode::leftNode() const {
    return leftNode_;
}
void TreeNode::setLeftNode(TreeNode* leftNode) {
    leftNode_ = leftNode;
}
TreeNode* TreeNode::rightNode() const {
    return rightNode_;
}
void TreeNode::setRightNode(TreeNode* rightNode) {
    rightNode_ = rightNode;
}