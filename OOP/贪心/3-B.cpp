#include <iostream>
using namespace std;

int a, b, c, d;

int main(){
    int flag = 0;
    cin>>a>>b>>c>>d;
    if(a==d){
        if(c == 0) flag = 1;
        else if(a != 0 && d != 0) flag = 1;
    }
    cout << flag << endl;
    return 0;
}
