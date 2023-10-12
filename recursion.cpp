#include <bits/stdc++.h>
using namespace std;



int recursion_2(int n, int res){
    if(n==0){
        return res;
    }
    return recursion_2(n-1, n+res);
}

int recur(int n) {
    // 终止条件
    if (n == 1)
        return 1;
    return n + recur(n - 1);
}

int main(){
    stack<int> s;
    int res = 0;
    for (int i=0 ;i<10;i++){
        s.push(i);
    }
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    cout<<res<<"\n";
}