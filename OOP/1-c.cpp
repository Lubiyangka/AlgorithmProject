#include<iostream>
using namespace std;

int a[2000][2000];
int le[2000];
int n, m;

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            char c;
            // scanf("%c", &c);
            cin>>c;
            a[i][j] = c - 48;
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            le[j] += a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < m; j++){
            if(le[j] - a[i][j] == 0){
                flag = false;
            }
        }
        if(flag){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}