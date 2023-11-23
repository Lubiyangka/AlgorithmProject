#include <bits/stdc++.h>
using namespace std;

int bf(string& s_1, string& s_2){
    int i = 0;
    int j = 0;
    while(i < s_1.size() && j < s_2.size()){
        //判断回溯条件
        if(s_1[i] == s_2[j]){
            i++;
            j++;
        }
        //回溯
        else{
            //长串index回到匹配起点
            i = i - j + 1;
            //短串indec回到起点
            j = 0;
        }
    }
    if(j == s_2.size()){
        //短串匹配成功，返回长串对应的index
        return i - j;
    }else{
        //匹配失败
        return -1;
    }
}

void getNext(string& str, int* next){
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < (int)str.size() - 1){
        if(k == -1 || str[j] == str[k]){
            k++;
            j++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}

int kmp(string& s_1, string& s_2){
    int i = 0;
    int j = 0;
    const int sLen = (int) s_2.size();
    int next[sLen];
    getNext(s_2, next);
    while(i < (int)s_1.size() && j < (int)s_2.size()){
        //判断回溯条件
        if(j == -1 || s_1[i] == s_2[j]){
            i++;
            j++;
        }
        //回溯
        else{
            j = next[j];
        }
    }
    if(j == (int)s_2.size()){
        //短串匹配成功，返回长串对应的index
        return i - j;
    }else{
        //匹配失败
        return -1;
    }
}

int main(){
    string s_1 = "ookeabcabbbddfjdd";
    string s_2 = "abcab";
    cout<<bf(s_1, s_2)<<endl;
    cout<<kmp(s_1, s_2);
}