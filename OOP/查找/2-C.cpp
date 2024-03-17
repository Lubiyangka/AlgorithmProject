#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int m;
int x[100005];

int findByIndex(int s, int r){
    int l = 0;
    while(r > l){
        int mid = (l + r) / 2;
        if(x[mid] >= s) r = mid;
        else l = mid + 1;
    }
    return l;
}

bool flag(int midian){
    int sum = 0; 
    for(int i = 0; i < n; i++){
        sum += i - findByIndex(x[i] - midian, i);
        if(sum >= m) return true;
    }
    return false;
}
int main(){
    while(scanf("%d", &n) != EOF){
        memset(x, 0, sizeof x);
        for(int i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }
        m = (n * (n - 1) / 2 + 1) / 2;
        sort(x, x + n);

        int l = 0, r = x[n-1];
        while(r > l){
            int mid = (l + r) / 2;
            if(flag(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}