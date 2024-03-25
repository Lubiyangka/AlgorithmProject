#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int mm = 10000;
char a[mm][mm];

void fun(int n, int x, int y){
    if(n == 1){
        a[x][y] = 'X';
    }else{
        int m = pow(2, n-2);
        fun(n-1, x, y);
        fun(n-1, x + 2*m, y);
        fun(n-1, x+m, y+m);
        fun(n-1, x, y+ 2*m);
        fun(n-1, x+ 2*m, y+ 2*m);
    }
}
int main(){
    int n =0;
    while(cin >> n){
        int t = pow(3, n - 1);
        for(int i = 0; i < t; i++){
            for(int j = 0; j < t; j++){
                a[i][j] = ' ';
                a[i][t] = '\0';
            }
        }
        fun(n, 0, 0);
        for(int i = 0; i < t; i++){
            cout<<a[i]<<endl;
        }
        cout << "_" << endl;
    }
    return 0;
}