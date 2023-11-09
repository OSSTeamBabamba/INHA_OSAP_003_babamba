#ifndef AVLTREE_CSE_SET_H
#define AVLTREE_CSE_SET_H

class Set {
public:
    bool empty();
    int size();
    int erase(int key);
    int insert(int key);
    int find(int key);
    int minimum(int key);
    int maximum(int key);
    int rank(int key);

private:


};

#endif AVLTREE_CSE_SET_H

