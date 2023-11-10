#ifndef AVLTREE_CSE_SET_H
#define AVLTREE_CSE_SET_H
#include <utility>

class Set {
public:
    bool empty();
    int size();
    int erase(int key);
    int insert(int key);
    int find(int key);
    std::pair<int,int> minimum(int key);
    std::pair<int,int> maximum(int key);
    int rank(int key);

private:


};

#endif AVLTREE_CSE_SET_H

