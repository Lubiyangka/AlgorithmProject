#include <bits/stdc++.h>

using namespace std;

struct Tree {
    char val;
    Tree *left;
    Tree *right;
};

vector<char> v;

Tree *buildTree(string &str) {
    if (str.empty()) {
        return nullptr;
    }
    Tree *root = new Tree();
    root->val = str.front();
    root->left = nullptr;
    root->right = nullptr;
    if (str.front() >= 'a' && str.front() <= 'z') {
        str = str.substr(1);
        return root;
    }else {
        str = str.substr(1);
        root->left = buildTree(str);
        root->right = buildTree(str);
        return root;
    }
}

void preOrder(Tree *root) {
    if (root == nullptr) {
        return;
    }
    v.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Tree *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    v.push_back(root->val);
    inOrder(root->right);
}

void postOrder(Tree *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    v.push_back(root->val);
}

int main() {
    string s;
    cin >> s;
    Tree *root = buildTree(s);
    preOrder(root);
    for(char c: v){
        cout<<c;
    }
    printf("\n");
    v.clear();
    inOrder(root);
    for (char c: v) {
        cout << c;
    }
    printf("\n");
    v.clear();
    postOrder(root);
    for(char c:v){
        cout<<c;
    }
}