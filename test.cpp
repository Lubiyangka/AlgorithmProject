#include <bits/stdc++.h>

using namespace std;


int calculateResult(int a, int b, char o) {
    int re = 0;
    switch (o) {
        case '+':
            re = a + b;
            break;
        case '-':
            re = a - b;
            break;
        case '*':
            re = a * b;
            break;
        case '/':
            re = a / b;
            break;
        default:
            return 0;
    }
    return re;
}

int getPriority(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int calculateExpression(string &expression) {
    stack<int> num;
    stack<char> op;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            int temp = expression[i] - 48;
            for (int j = i + 1; j < expression.length(); j++) {
                if (!(expression[j] >= '0' && expression[j] <= '9')) {
                    i = j-1;
                    break;
                }
                temp = temp * 10 + expression[j] - 48;
            }
            num.push(temp);
//            cout<<temp<<"\n";
        } else if (expression[i] == '(') {
            op.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                char o = op.top();
                op.pop();
                int n_1 = num.top();
                num.pop();
                int n_2 = num.top();
                num.pop();
                int result = calculateResult(n_2, n_1, o);
                num.push(result);
            }
            op.pop();
        } else {
            while (!op.empty() && op.top() != '(' && getPriority(expression[i])<= getPriority(op.top())) {
                char o = op.top();
                op.pop();
                int n_1 = num.top();
                num.pop();
                int n_2 = num.top();
                num.pop();
                int result = calculateResult(n_2, n_1, o);
                num.push(result);
            }
            op.push(expression[i]);
        }
    }
    while (!op.empty()) {
        char o = op.top();
        op.pop();
        int n_1 = num.top();
        num.pop();
        int n_2 = num.top();
        num.pop();
        int result = calculateResult(n_2, n_1, o);
        num.push(result);
    }
   return num.top();
}


int main() {
    string expression;
    cin>>expression;
    cout << calculateExpression(expression) << endl;
    return 0;
}
