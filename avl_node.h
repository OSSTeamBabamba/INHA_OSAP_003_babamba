#ifndef AVLTREE_AVL_NODE_H
#define AVLTREE_AVL_NODE_H

#include <cstdint>

class AVLNode {

public:
    AVLNode() : key_(0x80000000), depth_(0), height_(0), parentNode_(nullptr), leftNode_(nullptr), rightNode_(nullptr) {};
    AVLNode(int32_t key, AVLNode* parentNode, AVLNode* leftNode, AVLNode* rightNode)
        : key_(key), depth_(0), height_(0), parentNode_(parentNode), leftNode_(leftNode), rightNode_(rightNode) {};


public:
    int32_t key() const;
    void setKey(int32_t key);
    int32_t depth() const;
    void setDepth(int32_t depth);
    int32_t height() const;
    void setHeight(int32_t height);
    AVLNode* parentNode() const;
    void setParentNode(AVLNode* leftNode);
    AVLNode* leftNode() const;
    void setLeftNode(AVLNode* leftNode);
    AVLNode* rightNode() const;
    void setRightNode(AVLNode* rightNode);

private:
    int32_t key_;
    int32_t depth_;
    int32_t height_;
    AVLNode* parentNode_;
    AVLNode* leftNode_;
    AVLNode* rightNode_;
};

#endif