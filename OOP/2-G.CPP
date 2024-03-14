#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

int n, m, line;

struct Stu{
    char id[5];
    int sc; 
}stu[5005];

bool cmp(Stu a, Stu b){
    if(a.sc > b.sc){
        return true;
    }else if(a.sc == b.sc){
        return a.id >= b.id; 
    }else{
        return false;
    }
}

int main(){
    ifstream fin("score.in");
    ofstream fout("score.out");
    if(!fin.is_open()) return -1;
    fin >> n >> m;
    line = (int) m * 1.5;
    for(int i = 0; i < n; i++){
        fin >> stu[i].id >> stu[i].sc;
    }

    sort(stu, stu + n, cmp);

    int scoreLine = stu[line].sc;
    int j = line;
    while(stu[j].sc == scoreLine ){
        j ++;
        line ++;
    }
    fout << scoreLine << " " << line << "\n";
    for(int i = 0; i < line; i++){
        fout << stu[i].id << " " << stu[i].sc << "\n";
    }
    fout.close();
    fin.close();
    return 0;
}