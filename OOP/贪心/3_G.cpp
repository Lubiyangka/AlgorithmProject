#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int t;
int a[1005];
int main(){
    cin >> t;
    while(t--){
        int n = 0;
        int sum = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int i = 0;
        for(i = n; i > 3; i -= 2){
            sum += min(a[1] + 2 * a[2] + a[i], 2 * a[1] + a[i-1] + a[i]);
        }
        if(i==3) sum=sum+a[1]+a[2]+a[3];
		else if(i==2) sum+=a[2];
		else sum+=a[1];
        cout << sum << endl;
    }
}