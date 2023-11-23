#include <bits/stdc++.h>

using namespace std;
struct Tree {
    char val;
    bool leftTag;
    bool rightTag;
    Tree *left;
    Tree *right;
};
Tree *pre = nullptr;

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

void threadTree(Tree *root) {
    if (root) {
        threadTree(root->left);

        if (root->left == nullptr) {
            root->leftTag = true;
            root->left = pre;
        }
        if (pre->right == nullptr) {
            pre->rightTag = true;
            pre->right = root;
        }
        pre = root;
        threadTree(root->right);
    }
}

bool in(Tree *Thrd, Tree *T) {
    Thrd->leftTag = false;
    Thrd->rightTag = true;
    Thrd->right = Thrd;
    if (T == nullptr) {
        Thrd->left = Thrd;
    } else {
        Thrd->left = T;
        pre = Thrd;
        threadTree(T);
        pre->right = Thrd;
        pre->rightTag = true;
        Thrd->right = pre;
    }
    return true;
}

void inOrder(Tree *root) {
    Tree *p = root->left;
    while (p != root) {
        while (!p->leftTag) {
            p = p->left;
        }
        cout << p->val;
        while (p->rightTag && p->right != root) {
            p = p->right;
            cout << p->val;
        }
        p = p->right;
    }
}

int findOneNode(Tree *root) {
    int count = 1;
    Tree *p = root->left;
    while (p != root) {
        while (!p->leftTag) {
            p = p->left;
        }
        if (!p->rightTag) {
            count++;
        }
        while (p->rightTag && p->right != root) {
            p = p->right;
            if (((!p->leftTag) && (p->rightTag)) || ((p->leftTag) && (!p->rightTag))) {
                count++;
            }
        }
        p = p->right;
    }
    return count;
}

int main() {
    string str;
    cin>>str;
    Tree *T = buildTree(str);
    Tree *Thrd = new Tree();
    in(Thrd, T);
    inOrder(Thrd);
    printf("\n");
    cout << findOneNode(Thrd);
    return 0;
}