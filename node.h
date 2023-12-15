/*
* node.h
*
* Copyright (c) 2023 seungbeomHu,Lee Soo-young, 박성훈, 정건우
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Created on: 2023-12-14
* Author: seungbeomHu,Lee Soo-young, 박성훈, 정건우
 */

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

#endif  // AVLTREESTL_NODE_H