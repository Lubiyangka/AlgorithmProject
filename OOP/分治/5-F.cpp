#include <iostream>
#include <algorithm>
using namespace std;

const int mm = 2e5 + 10;

int n, m, t;
struct point{
    int x, w;
    int id;
}points [mm];

bool cmpW(const point &a, const point &b){
    return a.w < b.w;
}

bool cmpX(const point &a, const point &b){
    return a.x < b.x;
}

int main() {
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> points[i].x >> points[i].w;
            points[i].id = i;
        }

        sort(points + 1, points + 1 + m, cmpW);
        sort(points + 1, points + 1 + 2 * n, cmpX);
        for(int i  = 1; i <= 2 * n; i++){
            ans += points[i].w;
        }
        cout << ans << endl;

        for(int i = 1; i <= n; i++){
            cout << points[i].id <<" "<< points[2 * n - i + 1].id<< endl;
        }
        cout << "\n";
    }
    return 0;
}