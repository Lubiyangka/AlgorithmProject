#include <bits/stdc++.h>

using namespace std;

const int M = 10005;
vector<int> graph[M];

void bfs(int val, int n, vector<int> &dis) {
    queue<int> q;
    vector<bool> isVisited(n + 1, false);
    q.push(val);
    isVisited[val] = true;
    dis[val] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!isVisited[next]) {
                q.push(next);
                isVisited[next] = true;
                dis[next] = dis[node] + 1;
            }
        }
    }
}

int main() {
    int m = 0, n = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    for (int i = 1; i <= m; i++) {
        vector<int> dis(m + 1, -1);
        bfs(i, m, dis);
        int c = 0;
        for (int j = 1; j <= m; j++) {
            if (dis[j] != -1 && dis[j] <= 6) {
                c++;
            }
        }

        // 计算百分比并输出结果
        double percent = (double) c / m * 100;
        cout << i << ": " << fixed << setprecision(2) << percent << "%\n";
    }
}