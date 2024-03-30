#include <iostream>
#include <algorithm>

using namespace std;

const int mm = 1e5 + 10;
int  n;
int an, am;
int a[mm], dp[mm], dp_[mm];



int main() {
    while(scanf("%d", &a[++n]) != EOF);
    n--;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        dp_[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            else dp_[i] = max(dp_[i], dp_[j] + 1);
        }
        am = max(am, dp[i]);
        an = max(an, dp_[i]);
    }
    cout << an <<"\n"<< am << endl;
}