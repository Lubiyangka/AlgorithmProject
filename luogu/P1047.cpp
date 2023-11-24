#include <iostream>

using namespace std;
bool t[10001];
int a[101];
int b[101];

int main() {
    int l = 0, n = 0;
    int cnt=0;
    cin >> l >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= l; i++) {
        t[i] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= b[i]; j++) {
            t[j] = false;
        }
    }
    for (int i = 0; i <= l; i++) {
        if(t[i]) cnt++;
    }
    cout<<cnt;
}