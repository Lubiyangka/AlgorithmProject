#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, sum, ans = 0x3f3f3f3f, a[50005];
bool flag = true;

int main(){
    int t = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= a[i]; j++){
            if(a[i] % j == 0){
                ans = min(ans, sum - a[i] - a[t] + a[i] / j + a[t] * j);
            }
        }
        if(flag) {
            flag = false;
            t--;
        }
    }
    cout << ans;
}