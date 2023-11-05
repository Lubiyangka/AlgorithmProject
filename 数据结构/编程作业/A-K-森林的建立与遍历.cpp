#include <bits/stdc++.h>

using namespace std;

struct Tree {
    char val;
    vector<Tree *> node;

    Tree(char v) : val(v) {}
};

queue<Tree *> q;
vector<char> out;
void buildTree(Tree *p) {
    char x, y, z;
    cin >> x >> z >> y;
    if (x == '#' && y == '#') {
        return;
    } else {
        Tree *root = new Tree(y);
        if (x == q.front()->val) {
            p->node.push_back(root);
            q.push(root);
            buildTree(p);
        } else {
            while (x != q.front()->val) {
                q.pop();
            }
            q.front()->node.push_back(root);
            q.push(root);
            buildTree(q.front());
        }
    }
    return;
}

void preOrder(Tree *root) {
    if(root->val != '/') {
        cout << root->val;
    }
    int size = root->node.size();
    for(int i = 0; i < size; i++){
        preOrder(root->node[i]);
    }
}

void postOrder(Tree *root){
    int size = root->node.size();
    for(int i = 0; i < size; i++){
        postOrder(root->node[i]);
    }
    if(root->val != '/') {
        cout << root->val;
    }
}

void levelOrder(Tree* root){
    Tree*p = root;
    queue<Tree*> temp;
    temp.push(p);
    while(!temp.empty()){
        p = temp.front();
        if(p->val != '/') {
            cout << p->val;
        }
        temp.pop();
        for(Tree* i: p->node){
            temp.push(i);
        }
    }
}

int depth(Tree* root){
    if(root->node.empty()){
        return 0;
    }
    int max = 1;
    int size = root->node.size();
    for(int i = 0; i < size; i ++){
        int t = depth(root->node[i]);
        if(max < t){
            max = t;
        }
    }
    return max+1;
}

int leafNum(Tree* root){
    if(root == nullptr){
        return 0;
    }
    if(root->node.empty()){
        return 1;
    }
    int t = 0;
    int size = root->node.size();
    for(int i = 0; i < size; i++){
        t += leafNum(root->node[i]);
    }
    return t;
}

void printPath(Tree* root){
    if(root == nullptr){
        return;
    }
    if(root -> val != '/'){
        out.push_back(root->val);
    }
    if(root->node.empty()){
        for(char i: out){
            cout<<i;
        }
        cout<<endl;
    }
    for(Tree* i: root->node){
        printPath(i);
    }
    out.pop_back();
}
int main() {
    char x, y, z;
    cin >> x >> z >> y;
    Tree *root = new Tree(y);
    q.push(root);
    buildTree(root);
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<depth(root) - 1<<endl;
    cout<<leafNum(root)<<endl;
    printPath(root);
}