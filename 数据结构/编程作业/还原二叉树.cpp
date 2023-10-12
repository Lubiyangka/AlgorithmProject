#include <bits/stdc++.h>
using namespace std;

struct Tree{
    char val;
    Tree* left;
    Tree* right;
};

Tree* buildTree(string perOrder, string inOrder){
    if(perOrder.empty()){
        return nullptr;
    }

    Tree* root = new Tree();
    root->val = perOrder[0];
    root->left = nullptr;
    root->right = nullptr;

    int index = inOrder.find(perOrder[0]);

    string leftPerOrder = perOrder.substr(1, index);
    string leftInOrder = inOrder.substr(0, index);
    root->left = buildTree(leftPerOrder, leftInOrder);

    string rightPerOrder = perOrder.substr(index+1);
    string rightInOrder = inOrder.substr(index+1);
    root->right = buildTree(rightPerOrder, rightInOrder);

    return root;
}

int depth(Tree* root){
    int left = 0, right = 0;
    if(root == nullptr){
        return 0;
    }
    left = depth(root->left);
    right = depth(root->right);
    if(left > right){
        return left + 1;
    }else{
        return right + 1;
    }
}

int leafNum(Tree* root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    return leafNum(root->left) + leafNum(root->right);
}
int main(){
    string s1;
    string s2;
    int treeDepth = 0;
    int leaf = 0;

    cin >> s1 >> s2;

    Tree* root = buildTree(s1, s2);
    treeDepth = depth(root);
    leaf = leafNum(root);
    cout<<treeDepth<<"\n";
    cout<<leaf;
}