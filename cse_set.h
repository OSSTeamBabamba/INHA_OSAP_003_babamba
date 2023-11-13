#ifndef AVLTREE_CSE_SET_H
#define AVLTREE_CSE_SET_H
#include <utility>

class Set {
public:
    virtual bool empty()=0;
    virtual int size()=0;
    virtual int erase(int key)=0;
    virtual int insert(int key)=0;
    virtual int find(int key)=0;
    virtual std::pair<int,int> minimum(int key)=0;
    virtual std::pair<int,int> maximum(int key)=0;
    virtual int rank(int key)=0;
};

#endif AVLTREE_CSE_SET_H

