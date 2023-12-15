#include "node.h"

int32_t Node::key() const { return key_; }

void Node::setKey(int32_t key) { key_ = key; }

int32_t Node::size() const { return size_; }

void Node::setSize(int32_t size) { size_ = size; }