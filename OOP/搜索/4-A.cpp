#include <iostream>
#include <cstring>
using namespace std;

int t, len, ans;
bool flag;
// char s[105];
string sp;

bool isMatched(int x, int y){
    return x < len / 2 && y < len / 2;
}

int main(){
    cin >> t;
    while(t--){
        cin >> sp;
        len = (int) sp.length();
        flag = true;
        ans = 0;
        int x = 1, y = 1;
        if(sp[0] == 'S') x++;
        else y++;
        if(sp[len - 1] == 'S') x++;
        else y++;
        if(!isMatched(x, y)) {
            cout << ans << endl;
            continue;
        }
        for(int i = 1; i < len - 1 && flag; i++){
            if(!isMatched(x, y)) {
                flag = false;
                continue;
            }
            if(sp[i] == 'S'){
                if(x < len / 2) x += 2;
                else y += 2; 
            }else x++, y++;
        }
    }
}
