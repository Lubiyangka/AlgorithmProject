#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;
int main(){
    unordered_map<int, string> map;
    map[23] = "ղķ˹";
    map[24] = "�ǵ�";
    map[30] = "����";
    map[11] = "����ɭ";

    string name = map[11];
    for(auto k: map){
        cout<<k.first<<"->"<<k.second<<"\n";
    }
    map.erase(11);
    for(auto k: map){
        cout<<k.first<<" "<<k.second<<"\n";
    }

}