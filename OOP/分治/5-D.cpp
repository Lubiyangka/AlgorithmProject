#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std ;
typedef long long LL;
const int MAX = 1e5+10 ;
const int inf = 0x3f3f3f3f ;
LL a[MAX];
int n , k , A , B ;
LL solve(LL l ,LL r){
	LL mid = (l+r)/ 2  ;
	LL ans ;
	int num = upper_bound(a+1,a+1+k,r)-lower_bound(a+1,a+1+k,l) ;
	if(num == 0 ){
		ans = A ;
	}
	else{
		ans = B*num*(r-l+1) ;
		if(r-l>=1){
			ans = min(ans,solve(l,mid)+solve(mid+1,r)) ;
		}
	}
	return ans ;
}
int main(){
  
    cin >> n >> k >> A >>B;
    for(int i = 1 ; i<=k ; i++ ){
    	scanf("%I64d",&a[i]);
	}
	sort(a+1,a+1+k) ;
	
	cout<<solve(1,1LL<<n)<<endl ;
	return 0 ;
}