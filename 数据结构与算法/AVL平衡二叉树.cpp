#include <bits/stdc++.h>
using namespace std;

struct Tree{
    char val;
    Tree* left;
    Tree* right;
};
//左旋
void leftRotate(Tree * p){
    Tree * root = p->right;
    p->right = root->left;
    root -> left = p;
    p = root;
}
//右旋
void rightRotate(Tree * p){
    Tree * root = p->left;
    p->left = root->right;
    root->right = p;
    p = root;
}