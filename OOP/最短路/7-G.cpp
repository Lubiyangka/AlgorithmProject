#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int mm = 110;
const int mmm = 10010;

int n, cnt, q, ans;
int head[mm];
struct Edge{
    int from, to, w;
}edge[mmm];

bool cmp(const Edge &x, const Edge &y) {
    return x.w < y.w;
}

int find(int x) {
    return head[x] == x ? x : head[x] = find(head[x]);
}

void kruskal(){
    sort(edge + 1, edge + cnt + 1, cmp);
    for(int i = 1; i <= n; ++i) head[i] = i;
    for(int i = 1; i <= cnt; ++i) {
        int x = find(edge[i].from), y = find(edge[i].to);
        if(x != y) {
            head[y] = x;
            ans += edge[i].w;
        }
    }
}

void add(int from, int to, int w){
    edge[++cnt].to = to;
    edge[cnt].w = w;
    edge[cnt].from = from;
}

int main(){
    scanf("%d", &n);
    int a[mm][mm];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &q);
    while(q--){
        int o, p;
        scanf("%d %d", &o, &p);
        a[o][p] = a[p][o] = 0;
    }
    for (int i = 1; i <= n ; ++i) {
        for(int j = 1; j <= i; ++j){
            add(i, j, a[i][j]);
        }
    }
    kruskal();
    printf("%d\n", ans);
    return 0;
}



