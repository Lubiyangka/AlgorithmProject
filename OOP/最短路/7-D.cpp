#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

/*
 * https://www.luogu.com.cn/problem/P2419
 */

struct node {
    int x, w;

    bool operator<(const node &b) const {
        return w > b.w;
    }
};

using namespace std;
const int mm = 1010;
const int mmm = 2010;
int t, n, cnt;
bool a[mm][mm];
int head[mm];
bool final[mm];
int dis[mm];

struct Edge {
    int to, w, next;
} edge[mmm];

void add(int u, int v, int w) {
    edge[++cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra(int s) {
    priority_queue<node> q;
    memset(dis, 0x3f, sizeof dis);
    memset(final, false, sizeof final);
    dis[s] = 0;
    q.push((node){s, 0});
    while(!q.empty()){
        int u = q.top().x;
        q.pop();
        if(final[u]) continue;
        final[u] = true;
        for(int k = head[u]; k; k = edge[k].next){
            int v = edge[k].to;
            if(dis[v] > dis[u] + edge[k].w){
                dis[v] = dis[u] + edge[k].w;
                q.push((node){v, dis[v]});
            }
        }
    }
}

int main() {
    scanf("%d %d", &t, &n);
    while (t--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        add(x, y, w);
        add(y, x, w);
    }
    dijkstra(n);
    printf("%d\n", dis[1]);
    return 0;
}