#include <cstdio>

using namespace std;
const int mm = 110;
int n, m, ans;
bool f[mm][mm];
/*
 * https://www.luogu.com.cn/problem/P2419
 */
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x, y;   
        scanf("%d %d", &x, &y);
        f[x][y] = true;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i][j] || f[i][k] && f[k][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int flag = 1;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            flag = flag && (f[i][j] || f[j][i]);
        }
        ans += flag;
    }
    printf("%d\n", ans);
    return 0;
}