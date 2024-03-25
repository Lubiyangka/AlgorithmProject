#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int x, y, n;

double dfs(double x, double y, int k){
    if(k == 1) return max(x, y) * 1.0 / min(x, y);

    double ans = 0x3f3f3f3f, t1, t2;
    double mx = x * 1.0 / k, my = y * 1.0 / k;
    for(int i = 1; i <= k / 2; i++){
        t1 = max(dfs(mx * i, y, i), dfs(x - mx * i, y, k - i));
        t2 = max(dfs(x, my * i, i), dfs(x, y - my * i, k - i));
        ans = min(ans, min(t1, t2));
    }
    return ans;
}

int main(){
    cin >> x >> y >> n;
    printf("%.6lf\n", dfs(x, y, n));
    return 0;
}