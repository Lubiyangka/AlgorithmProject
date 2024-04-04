#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 210
#define M 40010

const int inf = 0x3f3f3f3f;
using namespace std;
int n, ans;
int head[N];
bool vis[N];
double dis[N];
int x[N], y[N];
double mis[N][N];

/*
 * http://poj.org/problem?id=2253
 */

int read() {
    int s = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
    return f ? -s : s;
}


void dijkstra() {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dis[i] = 1e9;
    }
    dis[1] = 0;
    for (int i = 1; i <= n; ++i) {
        double mi = inf;
        int u = 1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && mi > dis[j]) {
                mi = dis[j];
                u = j;
            }
        }
        vis[u] = true;
        for(int j = 1; j <= n; j++){
//            double ma = max(dis[u], mis[u][j]);
//            dis[j] = min(ma, dis[j]);
            if(dis[j]>dis[u] && dis[j]>mis[u][j])
                dis[j] = max(dis[u], mis[u][j]);

        }
    }

}

int main() {
    ans = 1;
    while (n = read(), n != 0) {
        for (int i = 1; i <= n; ++i) {
            x[i] = read();
            y[i] = read();
        }
        memset(mis, 0, sizeof(mis));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                if(i == j) continue;
                mis[i][j] = mis[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            }
        }
        dijkstra();
        printf("Scenario #%d\n", ans++);
        printf("Frog Distance = %.3f\n\n", dis[2]);
    }
}