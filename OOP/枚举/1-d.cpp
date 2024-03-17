#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxm = 50000;
int prime[6000], cnt, m, a, b;
bool flag[maxm+5];

void pre()
{
	for(int i=2;i<=50000;i++)if(!flag[i])
	{prime[++cnt]=i;
		for(int j=i*i;j<=maxm&&j>0;j+=i)//j可能会溢出
			flag[j]=1;
	}
	return ;
}

int main()
{
	pre();
	while(scanf("%d%d%d",&m,&a,&b),m|a|b)
	{
		int ans1=0,ans2=0;
		for(int i=1;i<=cnt;i++)
			for(int j=i;j<=cnt;j++){
				int p=prime[i],q=prime[j];
				if(a*q<=b*p&&p*q<=m){
					if(p*q>ans1*ans2)
						ans1=p,ans2=q;
				}
				else break;
			}
		printf("%d %d\n",ans1,ans2);
	}
}