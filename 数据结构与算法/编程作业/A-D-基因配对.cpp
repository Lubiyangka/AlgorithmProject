// A-D-基因配对
#include <bits/stdc++.h>

using namespace std;
const int N = 100;
string strList[N], str;
int mi,mj;
double matchRate;

int main() {
    int length = 0;
    cin >> length;
    for (int i = 1; i <= length; i++) {
        cin >> strList[i];
    }
    cin>>str;
    for (int i = 1; i <= length; i++) {
        int strListLen = strList[i].size();
        int strLen = str.size();
        for(int j=0;j<strListLen-strLen+1;j++){
            int temp=0;
            for(int k=0;k<strLen;k++){
                if(strList[i][j+k] == str[k]){
                    temp++;
                }
            }
            double t = temp*1.0/strLen;
            if(t>matchRate){
                matchRate=t;
                mi=i;
                mj=j+1;
            }
        }
    }
    if(matchRate!= 0){
        printf("%d %d %0.2lf%%\n", mi, mj, matchRate*100);
    }else{
        cout<<"0 0 0.00%\n";
    }
}