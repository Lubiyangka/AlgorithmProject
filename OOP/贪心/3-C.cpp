#include <iostream>
using namespace std;

int t, n, x, y, ans;
char s[200005];

int main(){
    cin >> t;
    while(t--){
        bool f = true;
        cin >> n >> s + 1;
        x = 1, y = 1;
        for (int i = 1;s[i];i++)
		{
			if (s[i] == 'R')x++;
			else y++;
			if (s[i] != s[i - 1] && i != 1)f = false;
		}
		if (f == 1)
		{
			cout << n << '\n';
			continue;
		}
		x = n - x, y = n - y;
		int i = 2;
		ans = 1;
		while (s[i] == s[i - 1])ans++, i++;
		for (i;s[i];i++)
		{
			ans++;
			if (s[i] == 'R')ans += y;
			else ans += x;
			if (s[i + 1] == 0)ans += (x + 1)*(y + 1);
		}
		cout << ans << '\n';
    }
}