#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct Point{
    int x, y;
};

const int max_n = 505;


int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int dp[max_n][max_n];
char p[max_n][max_n];
Point now, temp;
queue<Point> q;

int main(){
    int n, m, x2, y2, cns;
    while(scanf("%d%d", &n, &m), n!=0 || m!=0){
        for(int i = 1; i <= n; i++){
            scanf("%s", p[i] + 1);
        }
        scanf("%d%d%d%d", &now.x, &now.y, &x2, &y2);
        now.x++, now.y++, x2++, y2++;
        memset(dp, 62, sizeof(dp));
        dp[now.x][now.y] = 0;
        q.push(now);
        while(q.empty() == 0){
            now = q.front();
            q.pop();
            for(int i = 0; i <= 3; i++){
                temp.x = now.x + dir[i][0];
                temp.y = now.y + dir[i][1];
                if(temp.x < 1 || temp.x > n || temp.y < 1 || temp.y > m) continue;
                cns = 0;
                if(p[temp.x][temp.y] != p[now.x][now.y]) cns = 1;
                if(dp[now.x][now.y] + cns < dp[temp.x][temp.y]){
                    dp[temp.x][temp.y] = dp[now.x][now.y] + cns;
                    q.push(temp);
                }
            }
        }
        printf("%d\n", dp[x2][y2]);
    }
    return 0;
}