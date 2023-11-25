#include <vector>
#include<iostream>
#include<stack>

using namespace std;

//时间复杂度O（n+e）：点数+边数
//最大顶点个数
#define MAX_VERTEX_NUM 100

/*
 * 邻接表 = 顶点表（顺序存储） + 边链表（链式存储）
 */

//边链表
struct Arc {
    int adj;
    Arc *next;
};

//顶点表
struct VNode {
    char data;
    Arc *first;
};

//邻接表
struct Graph {
    VNode vertices[MAX_VERTEX_NUM];
    int vexNum;
    int arcNum;
};

//前插法建立边链表
void creatGraph(Graph &G) {
    cin >> G.vexNum >> G.arcNum;
    for (int i = 1; i <= G.vexNum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].first = nullptr;
    }
    for (int k = 0; k < G.arcNum; k++) {
        int i = 0, j = 0;
        cin >> i >> j;
        Arc *arc = new Arc();
        arc->adj = j;
        arc->next = G.vertices[i].first;
        G.vertices[i].first = arc;
    }
}

void findInDegree(Graph &G, int degree[]) {
    int i;
    Arc *p;
    for (i = 0; i < G.vexNum; i++) {
        p = G.vertices[i].first;
        while (p) {
            degree[p->adj]++;
            p = p->next;
        }
    }
}

int findVex(Graph &G, char v) {
    for (int i = 1; i <= G.vexNum; i++) {
        if (G.vertices[i].data == v) {
            return i;
        }
    }
    return -1;
}

bool topologicalSort(Graph &G) {
    stack<char> s;
    int count = 0;
    Arc *p;
    int degree[MAX_VERTEX_NUM];
    findInDegree(G, degree);
    for (int i = 1; i <= G.vexNum; i++) {
        if (!degree[i]) {
            s.push(G.vertices[i].data);
        }
    }
    while (!s.empty()) {
        int i = findVex(G, s.top());
        cout << G.vertices[i].data << "->";
        s.pop();
        count++;
        for (p = G.vertices[i].first; p != nullptr; p = p->next) {
            if (!(--degree[p->adj])) {
                s.push(G.vertices[p->adj].data);
            }
        }
    }
    return count < G.vexNum;
}