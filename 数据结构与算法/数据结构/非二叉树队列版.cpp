#include <bits/stdc++.h>

using namespace std;

struct Tree {
    char val;
    queue<Tree *> node;

    Tree(char v) : val(v) {}
};

queue<Tree *> q;

void buildTree(Tree *p) {
    char x, y, z;
    cin >> x >> z >> y;
    if (x == '#' && y == '#') {
        return;
    } else {
        Tree *root = new Tree(y);
        if (x == q.front()->val) {
            p->node.push(root);
            q.push(root);
            buildTree(p);
        } else {
            while (x != q.front()->val) {
                q.pop();
            }
            q.front()->node.push(root);
            q.push(root);
            buildTree(q.front());
        }
    }
    return;
}
// 先序遍历
void preOrder(Tree *root) {
    cout << root->val;
    while (!root->node.empty()) {
        preOrder(root->node.front());
        root->node.pop();
    }
}
//后序遍历
void postOrder(Tree *root){
    while (!root->node.empty()) {
        postOrder(root->node.front());
        root->node.pop();
    }
    cout << root->val;
}

int main() {
    char x, y, z;
    cin >> x >> z >> y;
    Tree *root = new Tree(y);
    q.push(root);
    buildTree(root);
//    preOrder(root);
    postOrder(root);
}