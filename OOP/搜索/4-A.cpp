#include <iostream>
#include <cstring> // 包含 C 字符串库
using namespace std;

const int mn = 55; // 字符串长度上限
const int inf = 1e9 + 7; // 一个较大的整数值，用于初始化动态规划数组

long long f[mn][mn][mn]; // 动态规划数组
string s; // 输入字符串
int n, t; // 字符串长度和测试用例数量
long long ans; // 存储最终答案

int main() {
    cin >> t; // 读取测试用例数量
    while (t--) { // 处理每个测试用例
        cin >> s; // 读取输入字符串
        n = (int) s.length(); // 获取字符串长度
        ans = 0; // 初始化答案
        for (int l = 0; l <= n; l++) { // 遍历所有可能的字符串长度
            memset(f, 0, sizeof(f)); // 将动态规划数组初始化为零
            f[0][0][l] = 1; // 设置初始状态
            for (int i = 1; i <= n; i++) { // 遍历字符串中的每个字符
                for (int j = 0; j <= n; j++) { // 遍历可能的左括号数量
                    for (int k = 0; k <= n; k++) { // 遍历可能的右括号数量
                        if (s[i - 1] == 'S') { // 如果当前字符是左括号
                            if (j - 1 >= 0 && k - 1 >= 0) f[i][j][k] += f[i - 1][j - 1][k - 1]; // 更新状态
                            if (j + 1 <= n && k + 1 <= n) f[i][j][k] += f[i - 1][j + 1][k + 1]; // 更新状态
                        } else { // 如果当前字符是右括号
                            if (j - 1 >= 0 && k + 1 <= n) f[i][j][k] += f[i - 1][j - 1][k + 1]; // 更新状态
                            if (j + 1 <= n && k - 1 >= 0) f[i][j][k] += f[i - 1][j + 1][k - 1]; // 更新状态
                        }
                    }
                }
            }
            ans += f[n][l][0]; // 累加结果
        }
        cout << ans << endl; // 输出答案
    }
    return 0; // 返回
}
