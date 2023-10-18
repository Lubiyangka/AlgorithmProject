#include <bits/stdc++.h>
#define MAX_NUM 100
using namespace std;
enum typeGraph {
    DG, WG, UDG, UWG
};

struct Graph {
    int type;
    int numNode;
    int numVax;
    char node[MAX_NUM];
    int vax[MAX_NUM][MAX_NUM];
};

Graph graph;

int findNode(char t) {
    for (int i = 0; i < graph.numNode; i++) {
        if (graph.node[i] == t) {
            return i;
        }
    }
    return -1;
}

void buildGraph() {
    int width = 1;
    char x, y;
    for (int i = 0; i < graph.numNode; i++) {
        cin >> graph.node[i];
    }
    if (graph.type == WG || graph.type == UWG) {
        for (int i = 0; i < graph.numVax; i++) {
            cin >> x >> y >> width;
            int m = findNode(x);
            int n = findNode(y);
            if (graph.type == WG) {
                graph.vax[m][n] = width;
            } else {
                graph.vax[m][n] = width;
                graph.vax[n][m] = width;
            }
        }
    } else {
        for (int i = 0; i < graph.numVax; i++) {
            cin >> x >> y;
            int m = findNode(x);
            int n = findNode(y);
            if (graph.type == DG) {
                graph.vax[m][n] = width;
            } else {
                graph.vax[m][n] = width;
                graph.vax[n][m] = width;
            }
        }
    }
}

bool finished(const bool *visited) {
    int counter = 0;
    for (int i = 0; i < graph.numNode; i++) {
        if (visited[i]) counter++;
    }
    return counter == graph.numNode;
}

string DFS(char x) {
    string str;
    bool visited[graph.numNode];
    for (int i = 0; i < graph.numNode; i++) visited[i] = false;
    int m = findNode(x);
    str.push_back(x);
    visited[m] = true;
    while (!finished(visited)) {
        int i = 0;
        for (i = 0; i < graph.numNode; i++) {
            if (graph.vax[m][i] > 0 && !visited[i]) {
                m = i;
                visited[m] = true;
                str.push_back(graph.node[m]);
                break;
            }
        }
        if (i == graph.numNode) {
            int j = 0;
            for (j = 0; j < graph.numNode; j++) {
                if (!visited[j]) {
                    m = j;
                    visited[m] = true;
                    str.push_back(graph.node[m]);
                    break;
                }
            }
            if(j == graph.numNode){
                str.push_back(graph.node[m]);
                visited[m] = true;
            }
        }
    }
    return str;
}

int main() {
    cin >> graph.type >> graph.numNode >> graph.numVax;
    buildGraph();
    char node;
    cin >> node;
    string result = DFS(node);
    cout << result;
}