#include <iostream>
using namespace std;

int n, m, k;
int t[10000];
bool flag[10000][10000];
int a[10000][10000];

int main(){
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1; j<=m;j++){
            if(flag[j][a[i][j]]) continue;
            flag[j][a[i][j]] = true;
            t[a[i][j]]++;
        }
    }
    for(int i = 1; i<= k;i++){
        cout<<t[i]<<" ";
    }
}