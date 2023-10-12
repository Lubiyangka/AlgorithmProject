#include <iostream>
#define M 100
using namespace std;

//访问数组
int access(int* num, int n){
    return num[n];
}

//增
void add(int* num, int n, int size, int index){
    for(int i = size - 1; i > index; i -- ){
        num[i] = num[i - 1];
    }
    num[index] = n;
}

//删
void remove(int* num, int size, int index){
    for(int i = index; i < size - 1; i++){
        num[i] = num[i + 1];
    }
}


int main(){
    //初始化数组
    int* num = new int[M] {1, 2, 3, 4, 5, 6};

    cout<<access(num, 3);

}   

