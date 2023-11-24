#include <vector>
#include<iostream>

using namespace std;
//最大值，表示无穷大
#define INF __INT_MAX__
//最大顶点个数
#define MAX_VERTEX_NUM 100

/*
 * 十字链表 = 顶点表（顺序存储） + 弧节点（链式存储）
 */

typedef enum {
    //有向图
    DG,
    //有向带权图
    DN,
    //无向图
    UDG,
    //无向带权图
    UDN
} GraphKind;

struct Arc {
    //弧尾
    int tail;
    //弧头
    int head;
    //弧头相同
    Arc *linkHead;
    //弧尾相同
    Arc *linkTail;
};

struct VNode {
    char data;
    //第一个入度节点
    Arc *firstIn;
    //第一个出度节点
    Arc *firstOut;
};
struct Graph {
    VNode vertices[MAX_VERTEX_NUM];
    int vexNum;
    int arcNum;
};

void CreatGraph(Graph &G) {
    cin >> G.vexNum >> G.arcNum;
    for (int i = 1; i <= G.vexNum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstOut = nullptr;
        G.vertices[i].firstIn = nullptr;
    }
    for (int k = 0; k < G.arcNum; k++) {
        int tail = 0, head = 0;
        cin >> tail >> head;
        Arc *arc = new Arc();
        arc->tail = tail;
        arc->head = head;
        arc->linkHead = nullptr;
        arc->linkTail = nullptr;
        arc->linkTail = G.vertices[tail].firstOut;
        G.vertices[tail].firstOut = arc;
        arc->linkHead = G.vertices[head].firstIn;
        G.vertices[head].firstIn = arc;
    }
}
void show(Graph &G){
    for(int i = 1; i <=G.vexNum;i++){
        Arc *current = G.vertices[i].firstOut;
        while(current != nullptr){
            cout<<"("<<current->tail<<","<<current->head<<")"<<endl;
            current = current->linkTail;
        }
    }
}

int main(){
    Graph G;
    CreatGraph(G);
    show(G);
}


