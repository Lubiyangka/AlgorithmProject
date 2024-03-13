#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <climits>
using namespace std;

int n, k;
double l, r, mid;
double le[10005];

bool flag(double x){
    int cnt = 0.0;
    for(int i = 0; i < n; i++){
        cnt += (int) (le[i] / x);
    }
    
    return cnt >= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%lf", &le[i]);
    }
    l = 0.0, r = 1e5+5;
    while(r - l > 1e-7){
        mid = (l + r) / 2;
        if(flag(mid)) l = mid;
        else r = mid;
    }
    printf("%.2f", floor(r * 100) / 100);
}