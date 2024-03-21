#include <iostream>
#include <string>
using namespace std;

int n, le, ans;
string s;

int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == ')') le++;
    }
    if (n % 2 == 1) {
        cout << ":(" << endl;
        return 0;
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '?'){
            if(le < n / 2){
                s[i] = ')';
                le ++;
            } else{
                s[i] = '(';
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '(') ans++;
        else ans --;
        if ((i != n - 1 && ans == 0) || ans < 0) {
            cout << ":(" << endl;
            return 0;
        }
    }
    if(!ans) cout << s << endl;
    else cout << ":(" << endl;
    return 0;
}