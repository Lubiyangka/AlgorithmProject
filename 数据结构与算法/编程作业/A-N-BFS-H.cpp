#include <bits/stdc++.h>

#define MAX_NUM 100
using namespace std;

struct ArcNode {
    int val;
    ArcNode *next;

    ArcNode(int x) : val(x), next(nullptr) {}
};

struct NodeList {
    int val;
    ArcNode *first;

    NodeList() {
        this->first = nullptr;
    }
};

struct Graph {
    int nodeNum;
    int vaxNum;
    NodeList vax[MAX_NUM];
};

ArcNode *nextNode(ArcNode *node) {
    return node->next;
}

ArcNode *getFirst(Graph &g, int v) {
    return g.vax[v].first;
}

void BFS(Graph &g) {
    int counter = 0;
    bool visited[g.nodeNum];
    vector<int> s;
    queue<int> q;
    for (bool b: visited) {
        b = false;
    }
    for (int i = 1; i <= g.nodeNum; i++) {
        if (!visited[i - 1]) {
            int temp = 0;
            q.push(i);
            visited[i - 1] = true;
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                temp++;
                for (ArcNode *j = getFirst(g, top); j != nullptr; j = nextNode(j)) {
                    if (!visited[j->val - 1]) {
                        visited[j->val - 1] = true;
                        q.push(j->val);
                    }
                }
//                if (temp != 1) {
//                    s.push_back(temp);
//                } else {
//                    counter--;
//                }
            }
            if(temp>=2){
                s.push_back(temp);
                counter++;
            }
        }
    }
    cout << counter << endl;
    std::sort(s.begin(), s.end());
    for (int i: s) {
        cout << i << " ";
    }
}

int main() {
    Graph graph;
    cin >> graph.nodeNum >> graph.vaxNum;
    int x = 0, y = 0;
    for (int i = 1; i <= graph.nodeNum; i++) {
        graph.vax[i].val = i;
    }
    for (int i = 0; i < graph.vaxNum; i++) {
        cin >> x >> y;
        ArcNode *m = new ArcNode(x);
        ArcNode *s = new ArcNode(y);
        s->next = graph.vax[x].first;
        m->next = graph.vax[y].first;
        graph.vax[y].first = m;
        graph.vax[x].first = s;
    }
    BFS(graph);
}