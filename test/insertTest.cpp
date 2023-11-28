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
         avltree->Insert(key);
    }
    for(int key : keys) {
        cout << "key: " << key << "\n";
        cout << "find depth : " << avltree->Find(key) << endl;
        cout << "depth : " << avltree->Rank(key).first << " rank: "<< avltree->Rank(key).second << endl;
        cout<<"cur minimum: "<<avltree->Minimum(key).first<<" key: "<<avltree->Minimum(key).second<<endl;
    }

    delete avltree;
    return 0;
}