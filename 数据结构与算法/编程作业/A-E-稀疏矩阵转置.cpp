#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
struct Node{
    int x;
    int y;
    int value;
}matrix[N];


int main() {

    int n=0,m=0,number = 0;
    cin >> n >> m >>number;
    for (int i = 1;i<=number;i++){
        cin>>matrix[i].y>>matrix[i].x>>matrix[i].value;
    }
    for(int i =1;i<number;i++){
        for(int j = number;j>i;j--){
            if(matrix[j].x<matrix[j-1].x){
                swap(matrix[j],matrix[j-1]);
            }
        }
    }
    cout << m<<" "<<n<<" "<<number<<"\n";
    for (int i =1;i<=number;i++){
        cout<<matrix[i].x<<" "<<matrix[i].y<<" "<<matrix[i].value<<"\n";
    }
    return 0;
}