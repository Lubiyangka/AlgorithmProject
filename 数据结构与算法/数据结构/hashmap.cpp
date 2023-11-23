#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;
int main(){
    unordered_map<int, string> map;
    map[23] = "’≤ƒ∑Àπ";
    map[24] = "««µ§";
    map[30] = "ø‚¿Ô";
    map[11] = "Ã¿∆’…≠";

    string name = map[11];
    for(auto k: map){
        cout<<k.first<<"->"<<k.second<<"\n";
    }
    map.erase(11);
    for(auto k: map){
        cout<<k.first<<" "<<k.second<<"\n";
    }

}