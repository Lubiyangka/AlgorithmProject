#include <iostream>
#include <algorithm>

/*
 * https://www.luogu.com.cn/problem/P1063
*/
using namespace std;

const int mm = 400;
int n, ans;
int a[mm], dp[mm][mm];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= n ; ++i) {
        for (int l = 1; l + i <= 2 * n ; ++l) { 
            int r = l + i;
            for (int k = l + 1; k < r; ++k) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i][i + n]);
    }
    cout << ans << endl;
    return 0;
}