#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
// 目标方向为30000，采用邻接矩阵的话30000会编译错误
const int mm = 30000;
int n, m;
int a[mm][mm];
int dis[mm];
bool final[mm];

void DIJ(int start) {
    for (int i = 1; i <= n; i++) {
        dis[i] = a[start][i];
    }
    final[start] = true;
    for (int i = 2; i <= n; i++) {
        int min = inf;
        int v = start;
        for (int j = 1; j <= n; ++j) {
            if (!final[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        final[v] = true;
        for (int j = 1; j <= n; ++j) {
            if (!final[j] && min + a[v][j] < dis[j]) {
                dis[j] = min + a[v][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(final, false, sizeof(final));
    for (int k = 1; k <= m; ++k) {
        int i = 0, j = 0;
        cin >> i >> j;
        cin >> a[i][j];
    }
    DIJ(1);
    cout << dis[n] << endl;
    return 0;
}