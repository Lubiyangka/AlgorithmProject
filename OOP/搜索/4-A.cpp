#include <iostream>
#include <cstring>
using namespace std;

const int mn = 55;
const int inf = 1e9 +7;

long long f[mn][mn][mn];
string s;
int n, t;
long long ans;

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        n = (int) s.length();
        ans = 0;
        for(int l = 0; l <= n; l++){
            memset(f, 0, sizeof(f));
            f[0][0][l] = 1;
            for(int i = 1; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    for(int k = 0; k <= n; k++){
                        if (s[i - 1] == 'S') {
                            if (j - 1 >= 0 && k - 1 >= 0) f[i][j][k] += f[i - 1][j - 1][k - 1];
                            if (j + 1 <= n && k + 1 <= n) f[i][j][k] += f[i - 1][j + 1][k + 1];
                        } else {
                            if (j - 1 >= 0 && k + 1 <= n) f[i][j][k] += f[i - 1][j - 1][k + 1];
                            if (j + 1 <= n && k - 1 >= 0) f[i][j][k] += f[i - 1][j + 1][k - 1];
                        }
                    }
                }
            }
            ans += f[n][l][0];
        }
        cout << ans << endl;
    }
    return 0;
}