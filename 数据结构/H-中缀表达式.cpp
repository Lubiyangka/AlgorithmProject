#include <bits/stdc++.h>

using namespace std;

struct Tree {
    char val;
    Tree *left;
    Tree *right;

    Tree(char x) : val(x), left(nullptr), right(nullptr) {}
};

stack<char> val;
stack<char> op;
vector<char> v;

bool compare(char x, char y) {
    if (x == NULL) {
        //TODO 还需要改进
        return true;
    }
    if ((x == '+' || x == '-') && (y == '*' || y == '/')) {
        return false;
    } else {
        return true;
    }

}

bool isValue(char x) {
    return x >= 'a' && x <= 'z';
}

Tree *buildTree(string &str) {
    Tree *p;
    bool tag = true;
    for (char i: str) {
        if (isValue(i)) {
            if (tag) {
                Tree *root = new Tree(i);
                p = root;
            }
            val.push(i);
        } else if (i == '(') {
            tag = false;
        } else if (i == ')') {
            Tree *root = new Tree(op.top());
            op.pop();
            root->right = new Tree(val.top());
            val.pop();
            root->left = new Tree(val.top());
            val.pop();
            p = root;
            tag = true;
        } else {
            if (compare(op.top(), i)) {
                op.push(i);
            }else{
                Tree *root = new Tree(i);
                while(!op.empty()){
                    root->left = new Tree(op.top());
                    op.pop();
                }
            }
        }
    }
    return p;
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
    for (char c: v) {
        cout << c;
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
    for (char c: v) {
        cout << c;
    }
}