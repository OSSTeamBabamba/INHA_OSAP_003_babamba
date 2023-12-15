#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstdint>

#include "node.h"

class TreeNode : public Node {
 public:
  TreeNode()
      : Node(0),
        depth_(0),
        height_(0),
        parentNode_(nullptr),
        leftNode_(nullptr),
        rightNode_(nullptr){};
  TreeNode(int32_t key, TreeNode* parentNode, TreeNode* leftNode,
           TreeNode* rightNode)
      : Node(key),
        depth_(0),
        height_(0),
        parentNode_(parentNode),
        leftNode_(leftNode),
        rightNode_(rightNode){};

 public:
  int32_t depth() const;
  void setDepth(int32_t depth);
  int32_t height() const;
  void setHeight(int32_t height);
  TreeNode* parentNode() const;
  void setParentNode(TreeNode* parentNode);
  TreeNode* leftNode() const;
  void setLeftNode(TreeNode* leftNode);
  TreeNode* rightNode() const;
  void setRightNode(TreeNode* rightNode);

 private:
  int32_t depth_;
  int32_t height_;
  TreeNode* parentNode_;
  TreeNode* leftNode_;
  TreeNode* rightNode_;
};

#endif
