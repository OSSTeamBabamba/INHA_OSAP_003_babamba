#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include "../avl_tree.h"
#include <gtest/gtest.h>

using namespace std;


TEST(SET_AVLTEST,eraseTest0){

  vector<int> insertkeys = {1};

  vector< pair<int,int> > keys = {{1,0}};
  Set* avltree = new AVLTree();

  for(auto key : insertkeys){
    avltree->Insert(key);
  }

  for(auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}


TEST(SET_AVLTEST,eraseTest1){

  vector<int> insertkeys = {1};

  vector< pair<int,int> > keys = {{2,0}};
  Set* avltree = new AVLTree();

  for(auto key : insertkeys){
    avltree->Insert(key);
  }

  for(auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST,eraseTest2){

  vector<int> insertkeys = {1,2,3,4,5,6,7,8,9,10};

  vector< pair<int,int> > keys = {{5,3},{4,0},{2,1},{9,2}};
  Set* avltree = new AVLTree();

  for(auto key : insertkeys){
    avltree->Insert(key);
  }

  for(auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST,eraseTest3){ // RR TEST

  vector<int> insertkeys = {1,2,3,4};

  vector< pair<int,int> > keys = {{1,1}};
  Set* avltree = new AVLTree();

  for(auto key : insertkeys){
    avltree->Insert(key);
  }

  for(auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}

TEST(SET_AVLTEST,eraseTest4){ // erase LR test

  vector<int> insertkeys = {5,6,1,3};

  vector< pair<int,int> > keys = {{6,1}};
  Set* avltree = new AVLTree();

  for(auto key : insertkeys){
    avltree->Insert(key);
  }

  for(auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}


TEST(SET_AVLTEST,eraseTest5){

  vector<int> insertkeys = {10,9,8,7,6,5,4,3,2,1};

  vector< pair<int,int> > keys = {{8,2},{9,1},{2,1},{4,2},{3,1},{1,1}};
  Set* avltree = new AVLTree();

  for(auto key : insertkeys){
    avltree->Insert(key);
  }

  for(auto key : keys) {
    ASSERT_EQ(key.second, avltree->Erase(key.first));
  }
}




int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
