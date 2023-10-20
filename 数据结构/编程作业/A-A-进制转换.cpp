#include <bits/stdc++.h>

using namespace std;

string DecimalToOther(int decimal, int other) {
    stack<int> s;
    string r = "";
    while (decimal > 0) {
        int temp = decimal % other;
        s.push(temp);
        decimal /= other;
    }
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        if (t < 10) {
            r += to_string(t);
        } else {
            char c = 'A' + (t - 10);
            r += c;
        }
    }
    return r;
}

int main() {
    int d = 0;
    int o = 0;
    cin >> d >> o;
    cout << DecimalToOther(d, o) << endl;

}