#include <iostream>

using namespace std;

int IBSN[11];

int main(){
    int i = 1;
    while(true){
        char c;
        scanf("%c", &c);
        if(c=='\n') break;
        if(c=='-') continue;
        IBSN[i] = c - '0';
        i++;
    }
    int sum = 0;
    for(int i = 1; i < 10; i++){
        sum += i*IBSN[i];
    }
    sum %=11;
    if(sum==IBSN[10]){
        cout<<"Right";
    }else{
        for(int i = 1; i < 10; i++){
            cout<<IBSN[i];
            if(i == 1||i==4 ||i==9) cout<<"-";
        }
        cout<<sum;
    }
}