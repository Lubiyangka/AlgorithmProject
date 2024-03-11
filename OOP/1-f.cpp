#include <iostream>
#include <algorithm>
using namespace std;

double A;
double dis(int n, int d){
    return A - 1.0*n/d;
}

int main(){
    int L = 0;
    double k, kk;
    double min = 100000*1.0;
    int n = 1, d = 1;
    cin>>A>>L;
    int p = 0, q = 0;
    while(n <= L && d <= L){
        k = dis(n, d);
        kk = abs(k);

        if(kk < min){
            min = kk;
            p = n;
            q = d;
        }
        
        if(k > 0){
            n++;
        }else{
            d++;
        }
    }
    cout<<p<<" "<<q<<"\n";
}