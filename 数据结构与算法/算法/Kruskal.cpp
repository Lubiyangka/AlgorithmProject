#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V;  // 图中顶点的数量
    vector<pair<int, pair<int, int>>> edges;  // 边的集合

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({weight, {src, dest}});
    }

    // 并查集的find操作
    int find(vector<int> &parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // 并查集的union操作
    void unionOp(vector<int> &parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    // Kruskal算法
    void kruskalMST() {
        vector<pair<int, pair<int, int>>> result;  // 存储最小生成树的边
        sort(edges.begin(), edges.end());  // 按权重对边进行排序

        vector<int> parent(V, -1);  // 初始化并查集

        for (auto edge : edges) {
            int src = edge.second.first;
            int dest = edge.second.second;

            int set_src = find(parent, src);
            int set_dest = find(parent, dest);

            if (set_src != set_dest) {
                result.push_back(edge);
                unionOp(parent, set_src, set_dest);
            }
        }

        // 输出最小生成树的边
        for (auto edge : result) {
            cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << endl;
        }
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    graph.kruskalMST();

    return 0;
}
