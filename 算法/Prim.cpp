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
};
struct Graph {
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
void CreatGraph(Graph &G) {
    double w;
    cin >> G.vexNum >> G.arcNum;
//    scanf("%d,%d,%d", &G.vexNum, &G.arcNum, &G.kind);
    for (int i = 1; i <= G.vexNum; i++) {
        cin >> G.vex[i];
    }
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            G.arc[i][j].width = INF;
        }
    }
    for (int i = 0; i < G.arcNum; i++) {
        int a = 0;
        int b = 0;
        int width = INF;
        cin >> a >> b >> width;
        G.arc[a][b].width = width;
        G.arc[b][a].width = width;
    }

}

int findVex(Graph &G, char vex) {
    for (int i = 1; i < G.vexNum; i++) {
        if (vex == G.vex[i]) {
            return i;
        }
    }
    return -1;
}

struct CloseDge {
    char vex;
    int lowCost;
};

void Prim(Graph &G, char v) {
    int index = findVex(G, v);
    CloseDge closeDge[G.vexNum + 1];
    for (int i = 1; i <= G.vexNum; i++) {
        if (i == index) {
            closeDge[i].lowCost = 0;
        } else {
            closeDge[i] = {v, G.arc[index - 1][i - 1].width};
        }
    }
    for (int i = 1; i <= G.vexNum; i++) {
        int min = INF;
        for (int j = 1; j <= G.vexNum; j++) {
            if (closeDge[j].lowCost != 0 && min > closeDge[j].lowCost) {
                min = closeDge[j].lowCost;
                index = j;
            }
        }
        cout << G.vex[index] << "->";
        closeDge[index].lowCost = 0;
        for (int j = 1; j <= G.vexNum; j++) {
            if (G.arc[index-1][j-1].width < closeDge[j].lowCost) {
                closeDge[j] = {G.vex[index], G.arc[index - 1][j - 1].width};
            }
        }
    }
}

int main() {
    Graph graph;
    CreatGraph(graph);
    char i = '0';
    Prim(graph, i);
}