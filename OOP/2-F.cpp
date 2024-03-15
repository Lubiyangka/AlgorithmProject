#include <iostream>
#include <cmath>
using namespace std;

const double eps = 5e-7;
int n, m;
int a[1005], b[1005];
double l, r = 1e9;
double mid;

bool flag(double f){
    double total = f + m;
    for(int i = 0; i < n; i++){
        total -= total / a[i];
        if(total < m && abs(total - m) > eps) return false;
        int d = (i + 1) % n;
        total -= total / b[d];
        if(total < m && abs(total - m) > eps) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] == 1){
            cout << -1;
            return 0;
        }
    }
    while(r - l > eps){
        mid = (l + r) / 2;
        if(flag(mid)) r = mid;
        else l = mid;
    }
    printf("%.8lf\n", l);
}