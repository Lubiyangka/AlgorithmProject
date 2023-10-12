#include <iostream>

using namespace std;

int main() {
    int tempB = 0;
    int tempA = 0;
    int res =0;
    int a = 0, b = 0, c = 0;
    for (int m = 1; m < 10; m++) {
        for(int i=1;i<10;i++){
            if(i<=m)continue;
            for(int j=0;j<10;j++){
                if(j*m<10)continue;
                if((i*10+j)%m!=1)continue;
                for(int k=0;k<10;k++){
                    res = i*100+j*10+k;
                    if(res%m!=7)continue;
                    cout<<res<<" "<<m<<"\n";
                }
            }
        }
    }
}