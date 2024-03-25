#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int mm = 25;
int n, m, u, k, ans;
char a[mm][mm];
bool f[mm][mm];

void move(int x, int y){
    f[x][y] = true;
    if(x < m -1 && a[x + 1][y] == '.' && f[x + 1][y] == false) move(x+1, y);
    if(x >= 1 && a[x - 1][y] == '.' && f[x - 1][y] == false) move(x-1, y);
    if(y < n -1 && a[x][y + 1] == '.' && f[x][y + 1] == false) move(x, y + 1);
    if(y >= 1 && a[x][y - 1] == '.' && f[x][y - 1] == false) move(x, y - 1);
}

int main(){
    while(cin >> n >> m, n != 0 && m != 0){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                if(a[i][j] == '@'){
                    u = i;
                    k = j;
                }
            }
        }
        memset(f, false, sizeof(f));
        ans = 0;
        move(u, k);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(f[i][j]) ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}