#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int m, n, L;
int x[50005];

bool flag(int mid){
    int now = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(x[i] - x[now] < mid) cnt ++;
        else now = i;
    }
    return cnt <= m;
}
int main(){
    ifstream fin("stone.in");
    ofstream fout("stone.out");
    if(!fin.is_open()) return -1;
    fin >> L >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> x[i];
    }
    x[n + 1] = L;
    int l = 0, r = L;
    while(r > l){
        int mid = (l + r + 1) / 2;
        if(flag(mid)) l = mid;
        else r = mid - 1;
    }
    fout << l;
    fout.close();
    fin.close();
    return 0;
}