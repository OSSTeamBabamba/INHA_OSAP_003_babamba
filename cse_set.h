/*
* cse_set.h
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
    virtual std::pair<int,int> Rank(int key) = 0;

};

#endif

