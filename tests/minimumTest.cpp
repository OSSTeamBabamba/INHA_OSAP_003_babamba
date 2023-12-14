#include<algorithm>
#include<vector>
#include<utility>
#include "../avl_tree.h"
#include <gtest/gtest.h>

using namespace std;


//값을 하나만 Insert 후 Minumum의 키
TEST(SET_AVLTEST, FindMinimumKey0) {
    Set* avlTree = new AVLTree();
    avlTree->Insert(1);  // 1 삽입

    // Test the Minimum function
    EXPECT_EQ(avlTree->Minimum(1).first, 0);  // 크기가 1인 트리의 Mimimum의 key는 트리에 포함된 유일한 값인 루트
}

//여러 값 Insert 후 Minumum의 키
TEST(SET_AVLTEST, FindMinimumKey1) {
    Set* avlTree = new AVLTree();
    vector<int> keys = {10,5,15,3,7,12,18};
    for(auto key : keys) avlTree->Insert(key);  // AVL트리에 keys 삽입

    // Test the Minimum function
    EXPECT_EQ(avlTree->Minimum(10).second, 3);  // 10을 루트로 하는 서브트리의 key는 3
    EXPECT_EQ(avlTree->Minimum(5).second, 3);    // 5를 루트로 하는 서브트리의 key는 3
    EXPECT_EQ(avlTree->Minimum(15).second, 12);  // 15을 루트로 하는 서브트리의 key는 12
    EXPECT_EQ(avlTree->Minimum(7).second, 7);  // 7을 루트로 하는 서브트리의 key는 7
    ASSERT_EQ(avlTree->Minimum(20).first, -1);   // 20은 해당 트리에 존재하지 않기에 -1 반환
}

//Insert 후 Minimum의 Depth
TEST(SET_AVLTEST, FindMinimumDepth) {
    Set* avlTree = new AVLTree();
    vector<int> keys = {10,5,15,3,7};
    //AVL트리에 keys 삽입
    for(auto key : keys) avlTree->Insert(key);

    // Test the Minimum function
    EXPECT_EQ(avlTree->Minimum(10).first, 2);  // 10을 루트로 하는 서브트리의 depth는 2
    EXPECT_EQ(avlTree->Minimum(5).first, 2);  // 5를 루트로 하는 서브트리의 depth는 2
    EXPECT_EQ(avlTree->Minimum(15).first, 1);  // 15를 루트로 하는 서브트리의 depth는 1
    ASSERT_EQ(avlTree->Minimum(20).first, -1); // 20은 해당 트리에 존재하지 않기에 -1 반환
}

//Insert 후 Minimum Node
TEST(SET_AVLTEST, FindMinimumNode) {
    Set* avlTree = new AVLTree();
    vector<int> keys = {10,5,15,3,7};
    //AVL트리에 keys 삽입
    for(auto key : keys) avlTree->Insert(key);

    // Test the Minimum function
    EXPECT_EQ(avlTree->Minimum(10), make_pair(2,3));  // 10을 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,3)
    EXPECT_EQ(avlTree->Minimum(5), make_pair(2,3));  // 5를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,3)
    EXPECT_EQ(avlTree->Minimum(15), make_pair(1,15));  // 15를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,12)
    EXPECT_EQ(avlTree->Minimum(3), make_pair(2,3));  // 3를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,3)
    EXPECT_EQ(avlTree->Minimum(7), make_pair(2,7));  // 7를 루트로 하는 서브트리의 Node는 (depth, Key)는 (2,7)
    ASSERT_EQ(avlTree->Minimum(20), make_pair(-1,-1)); // 20은 해당 트리에 존재하지 않기에 (-1,-1)이 반환
}


//삽입 및 삭제 연산 후 Minimum 노드
TEST(SET_AVLTEST, FindMinimumAfterErase) {
    Set* avlTree = new AVLTree();
    vector<int> keys = {10,5,15,3,7,12,18};
    for(auto key : keys) avlTree->Insert(key);  // AVL트리에 keys 삽입

    // Test the Minimum function
    EXPECT_EQ(avlTree->Minimum(3), make_pair(2,3));  // 3을 루트로 하는 서브트리의 (depth, Key)는 (2,3)
    EXPECT_EQ(avlTree->Minimum(10), make_pair(2,3));  // 10를 루트로 하는 서브트리의 (depth, Key)는 (2,3)
    EXPECT_EQ(avlTree->Minimum(15), make_pair(2,12));  // 15를 루트로 하는 서브트리의 (depth, Key)는 (2,12)

    avlTree->Erase(3); // AVL 트리에서 3을 키로 가진 노드 삭제
    EXPECT_EQ(avlTree->Minimum(10), make_pair(1,5)); //10을 루트로 하는 서브트리의 Minumum노드는 3에서 5로 변경
    ASSERT_EQ(avlTree->Minimum(3), make_pair(-1,-1)); //삭제된 3은 찾을 수 없다.
}
