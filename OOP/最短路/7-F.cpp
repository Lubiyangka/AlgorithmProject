#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int mm = 40;
const int mmm = 110;
int n, cnt, fa[mm];
struct node{
    int a, b, w;
}p[mmm];

bool cmp(const node &a, const node &b){
    return a.w < b.w;
}

int find(int x){
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

int kruskal(){
    int r = 0;
    sort(p, p + cnt, cmp);
    int ans = 0;
    for (int i = 1; i <= cnt ; ++i) {
        if(r == n-1) break;
        int x = find(p[i].a), y = find(p[i].b);
        if(x == y) continue;
        fa[x] = y;
        ans += p[i].w;
        r ++;
    }
    return ans;
}

int main(){
    while(scanf("%d", &n), n != 0){
        for(int i = 1; i <= 27; i++){
            fa[i] = i;
        }
        char c[10];
        cnt = 1;
        int a, b;
        for (int i = 1; i < n; ++i) {
            scanf("%s %d", &c, &a);
            int u = c[0] - 'A' + 1;
            for (int j = 0; j < a; ++j) {
                scanf("%s %d", &c, &b);
                int v = c[0] - 'A' + 1;
                p[cnt].a = u;
                p[cnt].b = v;
                p[cnt ++].w = b;
            }
        }
        printf("%d\n", kruskal());
    }
}