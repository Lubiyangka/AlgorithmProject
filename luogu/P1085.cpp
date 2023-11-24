#include<iostream>

using namespace std;

int main() {
    int a = 0;
    int max = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= 7; i++) {
        cin >> x >> y;
        if (x + y - 8 > max) {
            max = x + y -8;
            a = i;
        }
    }
    cout << a;
}