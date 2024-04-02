#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int inf = 0x3f3f3f3f;
const int mm = 200;
int n, t, mi, ma, tag;
int a[mm][mm];

int main() {
    while (~scanf("%d", &t) && t) {
        memset(a, inf, sizeof(a));
        for (int i = 1; i <= t; i++) {
            cin >> n;
            a[i][i] = 0;
            while (n--) {
                int w, j;
                cin >> j >> w;
                a[i][j] = w;
            }
        }
        for (int k = 1; k <= t; ++k) {
            for (int i = 1; i <= t; ++i) {
                for (int j = 1; j <= t; ++j) {
                    if (k == i || k == j || i == j)continue;
                    if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
        mi = inf;
        for (int i = 1; i <= t; ++i) {
            ma = 0;
            for (int j = 1; j <= t; ++j) {
                if(a[i][j] > ma)
                ma = a[i][j];
            }
            if(ma < mi) {
                mi = ma;
                tag = i;
            }
        }
        if(mi == inf) cout << "disjoint\n";
        else cout << tag <<" "<< mi << endl;
    }

    return 0;
}