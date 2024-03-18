#include <iostream>
#include <cstdio>
using namespace std;

int N, S;
int c[5005], y[10001];

int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> c[i] >> y[i];
    }
    long long sum = 0;

    for(int i = N; i > 0; i--){
        int min = c[i];
        for(int j = i - 1; j > 0; j--){
            if(c[j] + S * (i - j) < min) min = c[j] + S * (i - j);
        }
        sum += min * y[i];
    }
    printf("%lld", sum);
}