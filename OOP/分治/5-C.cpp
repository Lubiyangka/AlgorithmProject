#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int mm = 1e6+10;
int n, block;
struct Node{
    int l, r, id, b;
}que[mm];


int read()
{
	int sum=0,fh=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {sum=(sum<<3)+(sum<<1)+(ch^48);ch=getchar();}
	return sum*fh;
}

bool cmp(const Node &f, const Node &s){
    if(f.b != s.b) return f.b < s.b;
    if(f.b == 1) return f.r < s.r;
    return f.r > s.r;
}

int main(){
    n = read();
    block = 1000;
    for(int i = 1; i <= n; i++){
        que[i].l = read();
        que[i].r = read();
        que[i].id = i;
        que[i].b = (que[i].l - 1) / block + 1; 
    }
    sort(que + 1, que + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        cout << que[i].id << " ";
    }
    cout << "\n";
    return 0;
}