#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 150010
#define M 30010

using namespace std;
int n, m, s, add_edge;
int head[M], dis[M], vis[M];
struct UUU {
  int next, to, dis;
}edge[N];
struct node {
  int x, dis;
  bool operator < (const node &b) const {
    return dis > b.dis;
  }
};

int read() {
  int s = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}

void add(int from, int to, int dis) {
  edge[++add_edge].next = head[from];
  edge[add_edge].dis = dis;
  edge[add_edge].to = to;
  head[from] = add_edge;
}

void dijkstra(int s) {
  memset(vis, 0, sizeof vis);
  memset(dis, 0x3f, sizeof dis);
  priority_queue<node> q;
  q.push((node){s, 0}), dis[s] = 0;
  while (!q.empty()) {
    int x = q.top().x; q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = head[x]; i; i = edge[i].next) {
      int to = edge[i].to;
      if (!vis[to] && dis[to] > dis[x] + edge[i].dis) {
        dis[to] = dis[x] + edge[i].dis;
        q.push((node){to, dis[to]});
      }
    }
  }
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1, x, y, d; i <= m; i++) {
      x = read(), y = read(), d = read();
      add(x, y, d);
    }
    dijkstra(1);
    cout << dis[n] << "\n";
  }  
  
}