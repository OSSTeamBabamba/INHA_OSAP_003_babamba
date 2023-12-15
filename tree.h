#ifndef AVLTREESTL_TREE_H
#define AVLTREESTL_TREE_H

#include "node.h"
#include "tree_node.h"

class Tree {
 public:
  int Insert(int key);
  int Erase(int key);
  bool Empty();
  int Size();

 protected:
  TreeNode* root_;
  int32_t total_node_cnt;
};

#endif  // AVLTREESTL_TREE_H
