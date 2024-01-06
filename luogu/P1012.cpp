#include <iostream>
#include <algorithm>
using namespace std;

string s[20];
int n;

bool cmp(const string & s1, const string &s2){
    return (s1+s2>s2+s1);
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    sort(s, s+n, cmp);
    for(int i = 0; i < n; i++){
        cout<<s[i];
    }
}