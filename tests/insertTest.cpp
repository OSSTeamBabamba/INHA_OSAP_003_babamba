#include<algorithm>
#include<vector>
#include<utility>
#include "../avl_tree.h"
#include <gtest/gtest.h>

using namespace std;

TEST(SET_AVLTEST,InsertTest1){
    vector< pair<int,int> > keys = {{10,0},{80,1}, {30,0}, {3,2}, {5,1},{8,2}, {70,1}};
    Set* avltree = new AVLTree();
    for(auto key : keys) {
        ASSERT_EQ(key.second, avltree->Insert(key.first));
    }
}

TEST(SET_AVLTEST,InsertTest2){
    vector< pair<int,int> > keys = {{10,0},{80,1}, {30,0}, {3,2}, {5,1},{8,2}, {70,1}};
    Set* avltree = new AVLTree();
    for(auto key : keys) {
        ASSERT_EQ(key.second, avltree->Insert(key.first));
    }
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}