#include <bits/stdc++.h>

using namespace std;
vector<vector<string> > input;
vector<double> output;

void in() {
    int time = 0;
    cin >> time;
    for (int i = 0; i < time; i++) {
        vector<string> node;
        string str;
        int cnt = 0;
        while (true) {
            char temp;
            scanf("%c", &temp);
            if (temp == '#') {
                input.push_back(node);
                node.clear();
                break;
            }
            if (temp == '\n' || !((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))) {
                if (!str.empty()) {
                    bool isRepeated = false;
                    for (const string &k: node) {
                        if (k == str) {
                            isRepeated = true;
                        }
                    }
                    if (str.size() > 2 && !isRepeated) {
                        node.push_back(str);
                    }
                    str.clear();
                    cnt = 0;
                }
                continue;
            } else {
                if (temp >= 'A' && temp <= 'Z') {
                    temp += 32;
                }
                cnt++;
                if (cnt < 11) {
                    str.push_back(temp);
                }
            }
        }
    }
}

void out() {
    for (const vector<string> &i: input) {
        for (const string &j: i) {
            for (auto k: j) {
                cout << k;
            }
            cout << " ";
        }
        cout << "\n";
    }
}

double calculateSimilarity(int head, int tail) {
    int cnt = 0;
    double result;
    int size = (int) (input[head - 1].size() + input[tail - 1].size());
    for (const string &i: input[head - 1]) {
        for (const string &j: input[tail - 1]) {
            if (i == j) {
                cnt++;
            }
        }
    }
    result = (1.0 * cnt / (size - cnt));
    return result;
}

int main() {
    int time = 0;
    int x = 0, y = 0;
    double percent = 0;
    in();
    cin >> time;
    for (int i = 0; i < time; i++) {
        cin >> x >> y;
        percent = calculateSimilarity(x, y);
        percent *= 100.0;
        output.push_back(percent);
    }
    for (double i: output) {
        cout << fixed << setprecision(1) << i << "%" << endl;
    }
}