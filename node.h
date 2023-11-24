#ifndef AVLTREESTL_NODE_H
#define AVLTREESTL_NODE_H
#include<cstdint>

class Node{
public:
    int32_t key() const;
    void setKey(int32_t key);
public:
    Node(int32_t key): key_(key){}

protected:
    int32_t key_;
};

#endif //AVLTREESTL_NODE_H
