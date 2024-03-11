#include<iostream>
using namespace std;

int fun(int x){
    int sum = 0; 
    for(int i = 1; i * i <=x; i++){
        if(x%i == 0){
            if (i == 1) sum += i;
            else if (i * i == x) {
                sum += i;
            } else sum += i + x / i;
        }
    }
    return sum;
}

int main(){
    int a = 0, b = 0;
    int N = 0;
    cin>>N;
    int i = N;
    while(true){
        a = i;
        b = fun(a);
        if(a != b && a == fun(b)){
            if(a >= N){
                cout<<a<<" "<<b;
                break;
            }
        }
        i++;
    }
}