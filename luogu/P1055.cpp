#include <iostream>

using namespace std;

int IBSN[100];

int main() {
    string s;
    cin >> s;
    int len = s.size();
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (isdigit(s[i])) IBSN[++cnt] = s[i] - '0';
    int sum = 0;
    for (int i = 1; i < 10; i++) {
        sum += i * IBSN[i];
    }
    sum %= 11;
    if (sum == IBSN[10] || (sum == 10 && s[len - 1] == 'X')) {
        cout << "Right";
    } else {
        for (int i = 1; i < 10; i++) {
            cout << IBSN[i];
            if (i == 1 || i == 4 || i == 9) cout << "-";
        }
        if (sum == 10) {
            cout << "X";
        } else {
            cout << sum;
        }
    }
}