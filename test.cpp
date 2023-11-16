#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define M 1010

using namespace std;
int n, m, add_edge, tot, cnt;
int head[N], vis[N], ans[N];
struct node {
  int next, to;
}edge[N << 1];

int read() {
  int s = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}

void add(int from, int to) {
  edge[++add_edge].next = head[from];
  edge[add_edge].to = to;
  head[from] = add_edge;
}

void bfs(int st) {
  queue<int> q;
  q.push(st);
//  vis[st] = 1;
  while (!q.empty()) {
    int fr = q.front();
    q.pop();
    if (vis[fr]) continue;
    vis[fr] = 1;
    cnt++;
//    cout << fr << " ";
    for (int i = head[fr]; i; i = edge[i].next) {
      int to = edge[i].to;
      if (!vis[to]) q.push(to);
    } 
  } 
}

int main() {
  n = read(), m = read();
  for (int i = 1, x, y; i <= m; i++) {
    x = read(), y = read();
    add(x, y), add(y, x);
  }
  for (int i = 1; i <= n; i++) 
    if (!vis[i]) {
      cnt = 0;
      bfs(i);
      if (cnt >= 2) ans[++tot] = cnt;
//      puts("");
//      ans[tot] = cnt;
    }
  sort(ans + 1, ans + tot + 1);
  cout << tot << "\n";
  for (int i = 1; i <= tot; i++) cout << ans[i] << " ";
  puts("");
}