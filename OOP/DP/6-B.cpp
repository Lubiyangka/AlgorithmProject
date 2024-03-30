#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mm = 100;
int n, m;
int w[mm][mm], dp[2 * mm][mm][mm];

int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[2][1][1] = 0;
    for (int k = 3; k < m + n ; ++k) {
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n ; ++j) {
                int s = max(dp[k][i][j], dp[k - 1][i][j]);
                s = max(s, dp[k - 1][i - 1][j]);
                s = max(s, dp[k - 1][i][j - 1]);
                s = max(s, dp[k - 1][i - 1][j - 1]);
                if(s == -1) continue;
                dp[k][i][j] = s + w[k-i][i] + w[k - j][j];
            }
        }
    }
    cout << dp[m + n - 1][n - 1][n];
    return 0;
}