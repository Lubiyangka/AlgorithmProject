#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int high[10];
    for(int & i : high){
        cin>>i;
    }
    cin>>n;
    int cnt = 0;
    for(int i : high){
        if(i<=n+30) cnt++;
    }
    cout<<cnt;
}