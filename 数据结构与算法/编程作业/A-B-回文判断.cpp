#include <bits/stdc++.h>

using namespace std;

bool isPalindromic(string str) {
    deque<char> q;
    for (char i : str) {
        q.push_back(i);
    }
    while(!q.empty()){
        char front = q.front();
        char back = q.back();
        if(front == back){
            if(q.size() == 1){
                q.pop_back();
            }
            else{
                q.pop_front();
                q.pop_back();
            }
        }
        else{
            return false;
        }
    }
    return true;
}


int main() {
    string s;
    cin>>s;
    cout<<isPalindromic(s);
}