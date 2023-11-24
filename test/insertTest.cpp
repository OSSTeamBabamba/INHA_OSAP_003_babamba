#include<iostream>
#include<algorithm>
#include<vector>
#include "avl_node.h"
#include "avl_tree.h"
#include "node.h"
#include "tree_node.h"
#include "cse_set.h"
using namespace std;

int main(){
    Set* avltree = new AVLTree();

    vector<int> keys = {30, 20, 40, 10, 25, 50, 22};

    for(int key : keys){
        cout << "Insert: " << key << "\n";
        avltree.insert(key);
        cout << "\n";
    }
    return 0;

}