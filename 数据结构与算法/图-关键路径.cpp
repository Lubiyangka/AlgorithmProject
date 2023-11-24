#include <vector>
#include<iostream>
#include<stack>

using namespace std;

//最大顶点个数
#define MAX_VERTEX_NUM 20

/*
 * 邻接表 = 顶点表（顺序存储） + 边链表（链式存储）
 */

int ve[MAX_VERTEX_NUM], vl[MAX_VERTEX_NUM];
stack<char> t;
//边链表
struct Arc {
    int adj;
    Arc *next;
    int width;
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
        int width = 0;
        cin >> i >> j >> width;
        Arc *arc = new Arc();
        arc->adj = j;
        arc->width = width;
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
    int count = 0;
    stack<char> s;
    Arc *p;
    int degree[MAX_VERTEX_NUM];
    ve[G.vexNum] = {0};
    findInDegree(G, degree);
    for (int i = 1; i <= G.vexNum; i++) {
        if (!degree[i]) {
            s.push(G.vertices[i].data);
        }
    }
    while (!s.empty()) {
        int i = findVex(G, s.top());
        t.push(G.vertices[i].data);
        s.pop();
        count++;
        for (p = G.vertices[i].first; p != nullptr; p = p->next) {
            if (!(--degree[p->adj])) {
                s.push(G.vertices[p->adj].data);
            }
            if (ve[i] + p->width > ve[p->adj]) {
                ve[p->adj] = ve[i] + p->width;
            }
        }
    }
    return count < G.vexNum;
}

bool criticalPath(Graph &G) {
//    bool flag[G.arcNum];
    int k, dut;
    Arc *p;
    if (!topologicalSort(G)) {
        return false;
    }
//    for(bool i: flag){
//        i = false;
//    }
    for (int i = 1; i <= G.vexNum; i++) {
        vl[i] = ve[G.vexNum];
    }
    while (!t.empty()) {
        int j = findVex(G, t.top());
        cout << G.vertices[j].data << "->";
        t.pop();
        for (p = G.vertices[j].first; p != nullptr; p = p->next) {
            k = p->adj;
            dut = p->width;
            if (vl[k] - dut < vl[j]) {
                vl[j] = vl[k] - dut;
            }
        }
    }
    for(int i = 1; i<=G.vexNum;i++){
        for(p=G.vertices[i].first;p!= nullptr;p=p->next){
            k = p->adj;
            dut = p->width;
            if(ve[i] == vl[k]-dut){
//                flag[i] = true;
                cout<<i<<"->"<<k<<endl;
            }
        }
    }
    return true;
}