#include <bits/stdc++.h>

using namespace std;

struct Tree {
    char val;
    int weight;
    Tree *parent;
    Tree *left;
    Tree *right;
    vector<int> location;
    Tree(char v) : val(v), weight(0), parent(nullptr), left(nullptr), right(nullptr){}
};

vector<Tree *> base;
Tree *x;
Tree *y;
int cnt;
bool isInclude(char x) {
    for (Tree *i: base) {
        if (i->val == x) {
            i->weight++;
            return true;
        }
    }
    return false;
}

void sort() {
    for (int i = (int) base.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (base[j]->val > base[j + 1]->val) {
                swap(base[j], base[j + 1]);
            }
        }
    }
}

void selectTwoWeightMin() {
    int min1 = INFINITY;
    int index = 0;
    int min2 = INFINITY;
    for (int i = 0; i < (int) base.size(); i++) {
        if (base[i]->parent != nullptr) {
            continue;
        }
        if (min1 > base[i]->weight) {
            x = base[i];
            min1 = base[i]->weight;
            index =i;
        }
    }
    base.erase(base.begin() + index);
    for (int i = 0; i < (int) base.size(); i++) {
        if (base[i]->parent != nullptr) {
            continue;
        }
        if (min2 > base[i]->weight) {
            y = base[i];
            min2 = base[i]->weight;
            index =i;
        }
    }
    base.erase(base.begin() + index);
}

Tree *buildTree() {
    while ((int) base.size() > 1) {
        Tree *p = new Tree('#');
        selectTwoWeightMin();
        base.push_back(p);
        p->left = x;
        p->right = y;
        x->parent = p;
        y->parent = p;
        p->weight = x->weight + y->weight;
    }
    return base.front();
}

void longestPath(Tree* root){
    if(root->left==nullptr&&root->right== nullptr){
        return;
    }
    if(root->val == '#'){
        cnt += root->weight;
    }
    for(int i: root->location){
        root->left->location.push_back(i);
        root->right->location.push_back(i);
    }
    root->left->location.push_back(0);
    root->right->location.push_back(1);
    longestPath(root->left);
    longestPath(root->right);
}

void printNode(Tree* root){
    if(root == nullptr) return;
    if(root->left == nullptr&&root->right == nullptr){
        base.push_back(root);
    }
    printNode(root->left);
    printNode(root->right);
}
int main() {
    string str;
    Tree *root = new Tree('#');
    getline(cin, str);
    for (char i: str) {
        if (i == ' ') {
            continue;
        }
        if (isInclude(i)) {
            continue;
        }
        Tree *p = new Tree(i);
        p->weight++;
        base.push_back(p);
    }
    sort();
    root = buildTree();
    longestPath(root);
    base.clear();
    printNode(root);
    sort();
    for(Tree* i: base){
        cout<<i->val<<"("<<i->weight<<")";
        for(int j: i->location){
            cout<<j;
        }
        cout<<endl;
    }
    cout << cnt;
}