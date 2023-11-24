#include<iostream>

using namespace std;

int main() {
    int n = 0;
    int sum = 0;
    int i = 1;
    int t = 0;
    cin>> n;
    while(true){
        sum+=i;
        if(sum >= n) break;
        i++;
    }
    t = sum-n+1;
    cout<<t<<"/"<<i-t+1;
}