#include <vector>
#include<iostream>
using namespace std;
//最大值，表示无穷大
#define INF __INT_MAX__
//最大顶点个数
#define MAX_VERTEX_NUM 100

/*
 * 邻接表 = 顶点表（顺序存储） + 边链表（链式存储）
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


//边链表
struct Arc{
    int adj;
    int width;
    Arc* next;
};

//顶点表
struct VNode{
    char data;
    Arc *first;
};

//邻接表
struct Graph{
    VNode vertices[MAX_VERTEX_NUM];
    int vexNum;
    int arcNum;
    GraphKind kind;
};

//前插法建立边链表
void GreatGraph(Graph &G){
    cin>>G.vexNum>>G.arcNum;
    scanf("%d",&G.kind);
    for(int i = 1; i<=G.vexNum;i++){
        G.vertices[i].data = getchar();
        G.vertices[i].first = nullptr;
    }
    for(int k = 0; k< G.arcNum;k++){
        int i = 0,j = 0, width = 0;
        cin>>i>>j;
        Arc *arc = new Arc();
        arc->adj = j;
        arc->width = width;
        arc->next = G.vertices[i].first;
        G.vertices[i].first = arc;
    }
}


