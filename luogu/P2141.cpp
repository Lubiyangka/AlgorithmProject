#include <iostream>

using namespace std;

int t[20000], p[20000];
int a[105];
int n;
int cnt;
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        p[a[i]] = 1;
    }

    for(int i = 0; i< n;i++){
        for(int j = i + 1; j < n; j++){
            t[a[i]+a[j]]++;
        }
    }
    for(int i = 0; i < 10000; i++){
        if(t[i]!=0&&p[i]) cnt++;
    }
    cout<<cnt;
}