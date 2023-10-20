#include <bits/stdc++.h>

using namespace std;

struct Tree {
    char val;
    Tree *left;
    Tree *right;

    Tree(char x) : val(x), left(nullptr), right(nullptr) {}
};

vector<char> v;

bool isOp(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/';
}

Tree *buildTree(string str, int start, int end) {
    if(start > end){
        return nullptr;
    }

    //最低优先级
    int lowestP = INT_MAX;
    //最低优先级索引
    int lowestIndex = -1;
    //括号数量
    int counter = 0;

    for(int i = start; i <= end; i++){
        if(str[i] == '('){
            counter++;
        }else if(str[i] == ')'){
            counter--;
        }else if(counter == 0 && isOp(str[i])){
            //当前优先级
            int currentP;
            if(str[i] == '+' || str[i] == '-'){
                currentP = 1;
            }else{
                currentP = 2;
            }

            if(currentP <= lowestP){
                lowestP = currentP;
                lowestIndex = i;
            }
        }
    }

    if(lowestIndex == -1){
        if(str[start] == '(' && str[end] == ')' ){
            return buildTree(str, start+1,end - 1);
        }else{
            Tree* leaf = new Tree(str[start]);
            return leaf;
        }
    }else{
        Tree* root = new Tree(str[lowestIndex]);
        root->left = buildTree(str, start, lowestIndex - 1);
        root->right = buildTree(str, lowestIndex + 1, end);
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
    Tree *root = buildTree(s, 0, s.length() - 1);
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