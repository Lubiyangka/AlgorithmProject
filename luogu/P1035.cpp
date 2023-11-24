#include<iostream>

using namespace std;

int main() {
    int k = 0, i = 1;
    double sum = 0;
    cin>>k;
    while(true){
        sum += 1.0/i;
        if(sum > k){
            cout<<i;
            break;
        }
        i++;
    }
}