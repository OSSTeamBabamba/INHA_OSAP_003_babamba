#include<iostream>
#include<algorithm>
#include<vector>
#include "avl_tree.h"
using namespace std;

int main(){
    AVLTree* avltree = new AVLTree();

    vector<int> keys = {10, 80, 30, 3, 5, 8, 70};

    for(int key : keys) {
        cout << "Insert: " << key << "\n";
         avltree->insert(key);
         cout << "find depth : " << avltree->find(key) << endl;
         cout << "rank : " << avltree->rank(key) << endl;
    }

    avltree->inorderTraversal(avltree->getRoot());


    delete avltree;
    return 0;
}