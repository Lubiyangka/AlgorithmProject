#include<iostream>

using namespace std;

int main() {
    int n = 0, x = 0;
    int cnt = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while(t){
            if(t%10 == x) cnt++;
            t/=10;
        }
    }
    cout<<cnt;
}