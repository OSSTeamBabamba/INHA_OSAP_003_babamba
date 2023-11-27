#ifndef AVLTREE_CSE_SET_H
#define AVLTREE_CSE_SET_H

#include <utility>

class Set {
public:
    virtual bool Empty() = 0;
    virtual int Size() = 0;
    virtual int Erase(int key) = 0;
    virtual int Insert(int key) = 0;
    virtual int Find(int key) = 0;
    virtual std::pair<int, int> Minimum(int key) = 0;
    virtual std::pair<int, int> Maximum(int key) = 0;
    virtual int Rank(int key) = 0;

};

#endif

