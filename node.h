#ifndef AVLTREESTL_NODE_H
#define AVLTREESTL_NODE_H
#include <cstdint>

class Node {
public:
    Node(int32_t key) : key_(key), size_(1) {}

    int32_t key() const;
    void setKey(int32_t key);

    int32_t size() const;
    void setSize(int32_t size);

protected:
    int32_t key_;
    int32_t size_;
};

#endif //AVLTREESTL_NODE_H