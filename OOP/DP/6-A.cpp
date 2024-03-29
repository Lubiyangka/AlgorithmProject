/*
@author: Lubiyangka
Dilworth 定理
*/
#include <iostream>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mm = 1e5+3;
int n, t, h[mm], f[mm];

int main(){
    while(scanf("%d", &h[++n]) != EOF);
    for(int i = 0; i <= n; i++){
        cout << h[i]<< " ";
    }
    // n--;
    // memset(f, 0, sizeof(f));
    // f[0] = inf;
    // for(int i = 1; i <= n; i++){
    //     int l = 0; 
    //     int r = t + 1;
    //     while(r - l > 1){
    //         int m = l + (r - l) / 2;
    //         if(f[m] >= h[i]) l = m;
    //         else r = m;
    //     }
    //     int x = l + 1;
    //     if(x > t) t = x;
    //     f[x] = h[i];
    // }
    // t = 0;
    // memset(f, 0, sizeof(f));
    // f[0] = 0;
    // cout << t << endl;
    // for(int i = 1; i <= n; i++){
    //     int l = 0;
    //     int r = t + 1;
    //     while(r - l > 1){
    //         int m = l + (r- l) / 2;
    //         if(f[m] < h[i]) l = m;
    //         else r =m;
    //     }
    //     int x = 1 + l;
    //     if(x > t) t = x;
    //     f[x] = h[i]; 
    // }
    // cout << t << endl;
}
