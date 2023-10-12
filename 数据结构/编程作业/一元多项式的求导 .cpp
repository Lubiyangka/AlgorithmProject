#include <bits/stdc++.h>
using namespace std;
int tot = 1, a[10010];

int main() {
  while (~scanf("%d", &a[tot])) {
    tot++;
  }
  tot--;
  for (int i = 1; i <= tot; i++) {
    if (i % 2 == 1) a[i] *= a[i + 1];
    else {
		a[i]--;
		if (a[i] == -1) {
			tot = i - 2;
			break;
		}
	}
  }
  if (tot == 0) {
  	puts("0 0");
  	return 0;
  }
  for (int i = 1; i < tot; i++) {
    cout << a[i] << " ";
  }
  cout<<a[tot];
}