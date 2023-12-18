#include <iostream>

using namespace std;

int main() {
    int t = 0;
    char c;
    while (true) {
        scanf("%c", &c);
        if (c == '\n') break;
        if (c == ' ')continue;
        t++;
    }
    cout << t;
}