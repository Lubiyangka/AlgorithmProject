#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int t, n, a, ans, p[150005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(p, 0, sizeof(p));
        ans = -1;
        for(int i = 1; i <= n; i++){
            cin >> a;
            if(p[a]) ans = max(ans, - i + p[a] + n);
            p[a] = i;
        }
        cout << ans << endl;
    }
}