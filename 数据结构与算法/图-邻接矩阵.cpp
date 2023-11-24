#include <vector>
#include<iostream>
using namespace std;
//最大值，表示无穷大
#define INF __INT_MAX__
//最大顶点个数
#define MAX_VERTEX_NUM 100

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
    //边权
    int width;
    //弧相关指针
} ;
struct Graph{
    //顶点信息
    char vex[MAX_VERTEX_NUM];
    //弧信息
    Arc arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    //顶点数
    int vexNum;
    //弧数
    int arcNum;
    //图的类型
    GraphKind kind;
};

//建立有向网络（边带权）
void GreatGraph(Graph &G){
    double w;
    scanf("%d,%d,%d", &G.vexNum, &G.arcNum, &G.kind);
    for(int i = 1; i <= G.vexNum; i++){
        G.vex[i] = getchar();
    }
    for(int i = 1; i < G.vexNum;i++){
        for(int j = 1; j < G.vexNum; j++){
            G.arc[i][j].width = INF;
        }
    }
    for(int i = 1; i<G.arcNum;i++){
        int a = 0;
        int b = 0;
        int width = 0;
        cin>>a>>b>>width;
        G.arc[a][b].width = width;
        G.arc[b][a].width = width;
    }

}
