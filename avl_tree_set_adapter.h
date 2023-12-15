
#ifndef AVLTREESTL_AVL_TREE_SET_ADAPTER_H
#define AVLTREESTL_AVL_TREE_SET_ADAPTER_H

#include "avl_tree.h"
#include "cse_set.h"

class AVLTreeSetAdapter : public Set, AVLTree {
 public:
  int Insert(int key);
  int Erase(int key);
  bool Empty();
  int Size();
  int Find(int key);
  pair<int, int> Rank(int key);
  pair<int, int> Minimum(int key);
  pair<int, int> Maximum(int key);
};

#endif  // AVLTREESTL_AVL_TREE_SET_ADAPTER_H
