#include<iostream>
#include<algorithm>
#include<vector>
#include "avl_tree.h"
using namespace std;

int main(){
    Set* avltree = new AVLTree();

    vector<int> keys = {10, 20, 30, 10, 25, 50, 22};

    for(int key : keys){
        cout << "Insert: " << key << "\n";
         avltree->insert(key);
    }
    delete avltree;
    return 0;
}