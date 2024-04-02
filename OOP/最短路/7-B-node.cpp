#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int inf = 0x3f3f3f3f;
const int mm = 150010;
const int mmm = 30010;
int n, m, cnt;
int head[mmm];
int dis[mmm];
bool final[mmm];

struct node {
    int x, dis;

    bool operator<(const node &b) const {
        return dis > b.dis;
    }
};

// 链式前向星
struct Edge {
    int to, w, next;
} edge[mm];


void addEdge(int u, int v, int w) {
//    edge[++cnt].to = v;
//    edge[cnt].w = w;
//    edge[cnt].next = head[u];
//    head[u] = cnt;
    edge[++cnt].next = head[u];
    edge[cnt].w = w;
    edge[cnt].to = v;
    head[u] = cnt;
}

// 链式前向星 + Dijkstra
void dij(int start){
    dis[start] = 0;
    for(int i = 1; i < n; i++){
        int min = inf, v;
        for (int j = 1; j <= n; ++j) {
            if(!final[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        final[v] = true;
        for(int k = head[v]; k; k = edge[k].next){
            int e = edge[k].to;
            if(dis[e] > dis[v] + edge[k].w){
                dis[e] = dis[v] + edge[k].w;
            }
        }
    }
}

void dijPriQueue(int s) {

    priority_queue<node> q;
    q.push((node) {s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().x;
        q.pop();
        if (final[u]) continue;
        final[u] = true;
        for (int k = head[u]; k; k = edge[k].next) {
            int v = edge[k].to;
            if (!final[v] && dis[v] > dis[u] + edge[k].w) {
                dis[v] = dis[u] + edge[k].w;
                q.push((node) {v, dis[v]});
            }
        }

    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(final, false, sizeof final);
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
//            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
//    dij(1);
        dijPriQueue(1);
        cout << dis[n] << endl;
    }
}