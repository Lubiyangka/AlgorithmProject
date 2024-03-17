#include <iostream>
using namespace std;

int pow(int x){
    return x*x*x;
}
int main() {
    int M;
    cin >> M;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int p = 0; p < 10; p++){
                    int s = pow(i) + pow(j) + pow(k) + pow(p);
                    if(s >= M&&i*1000 + j*100 + k*10 + p == s){
                        cout<<s;
                        return 0;
                    }
                }
            }
        }
    }
}
