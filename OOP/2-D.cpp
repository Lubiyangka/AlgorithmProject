#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int a[105][2005];
int temp[105];

struct state{
    int x; 
    int i;
    int j;
    bool tag;

    state(int x = 0, int i = 0, int j = 0, bool tag = false):
        x(x), i(i), j(j), tag(tag){}
    
    bool operator > (const state &p) const {
        return this->x > p.x;
    }
};

priority_queue<state, vector<state>, greater<state> >q;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        state t;
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &a[i][j]);
            }
        }
        sort(a[0], a[0] + n);
        
        for(int k = 1; k < m; k++){
            sort(a[k], a[k] + n);
            while(!q.empty()){
                q.pop();
            }
            q.push(state(a[0][0] + a[k][0]));

            for(int l = 0; l < n; l++){
                t = q.top();
                q.pop();
                temp[l] = t.x;
                q.push(state(a[0][t.i] + a[k][t.j + 1], t.i, t.j + 1, true));
                if(!t.tag){
                    q.push(state(a[0][t.i + 1] + a[k][t.j], t.i + 1, t.j, true));
                }
            }
            for(int i = 0; i < n; i++){
                a[0][i] = temp[i];
            }
        }

        for(int i = 0; i < n; i++){
            printf("%d ", a[0][i]);
        }
    }
    return 0;
}