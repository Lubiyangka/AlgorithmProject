#include <iostream>
#include <cstring>
using namespace std;

struct node{
    int val;
    int id;
    node* left;
    node* right;
    node(int val, int id){
        this->val = val;
        this->id = id;
        left = nullptr;
        right = nullptr;
    }
};

const int mm = 100 + 5;
int t, n;
int a[mm];
int ans[mm];

node* buildTree(int p, int q, int dep){
    if(p == q) {
        return nullptr;
    }
    int mi = p;
    for(int i = p; i < q; i++){
        if(a[mi] < a[i]) mi = i;
    }
    node* root = new node(a[mi], mi);
    ans[mi] = dep;
    root->left = buildTree(p, mi, dep + 1);
    root->right = buildTree(mi + 1, q, dep + 1);
    return root;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++) cin >> a[i];  
        cout << 1;
        buildTree(0, n, 0);
        cout << 1;
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}