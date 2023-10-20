#include <bits/stdc++.h>
using namespace std;

struct Tree{
    char val;
    Tree* left;
    Tree* right;
};

vector<char> vec;

Tree* buildTree(string& str){
    if(str.front() == '#'){
        str = str.substr(1);
        return nullptr;
    }
    Tree* root = new Tree();
    root->val = str.front();
    str = str.substr(1);
    root->left = buildTree(str);
    root->right = buildTree(str);
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

void preOrder(Tree* root){
    if(root==nullptr){
        return;
    }
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Tree* root){
    if(root==nullptr){
        return;
    }
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

void postOrder(Tree* root){
    if(root==nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

void inOrderWithoutRecursion(Tree* root){
    if(root == nullptr){
        return;
    }
    Tree* p = root;
    stack<Tree*> s;
    while(!s.empty()||p){
        if(p){
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top();
            s.pop();
            cout<<p->val;
            p = p->right;
        }
    }
}

int main() {
    string str;
    cin>>str;
    int treeDepth = 0;
    int leaf = 0;
    Tree* root = buildTree(str);
    treeDepth = depth(root);
    leaf = leafNum(root);
    preOrder(root);
    for(char c:vec){
        cout<<c;
    }
    cout<<"\n";
    vec.clear();
    inOrder(root);
    for(char c:vec){
        cout<<c;
    }
    cout<<"\n";
    vec.clear();
    postOrder(root);
    for(char c:vec){
        cout<<c;
    }
    cout<<"\n";
    vec.clear();
    cout<<leaf<<"\n";
    cout<<treeDepth<<"\n";
    inOrderWithoutRecursion(root);
}