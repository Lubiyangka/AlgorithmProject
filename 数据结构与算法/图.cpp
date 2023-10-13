#include <vector>
#include<iostream>

#define INF __INT_MAX__
#define MAX_VERTEX_NUM 100

typedef enum {
    DG, DN, UDG, UDN
} GraphKind;

//typedef struct ArcCell {
//    int adj;
//    ArcCell *linked;
//
//} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct Arc {
    int start;
    int end;
    int width = 1;
} Arc;

class Graph {
private:
    char v[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexNum;
    int arcNum;
    GraphKind kind;
public:
    Graph(int vex, GraphKind kind, const char *nodes, const std::vector<Arc> &arcs);

    ~Graph();

    void insert(char v, const std::vector<Arc> &arcs);

    void remove(char v);

    void DFS(char v);

    void BFS(char v);

    void show();
};

Graph::Graph(int vex, GraphKind kind, const char *nodes, const std::vector<Arc> &arcs) : vexNum(vex), kind(kind) {
    for (int i = 0; i < this->vexNum; i++) {
        this->v[i] = nodes[i];
    }
    for (auto a: arcs) {
        if (kind == UDG || kind == UDN) {
            this->arcs[a.start][a.end] = a.width;
            this->arcs[a.end][a.start] = a.width;
        } else {
            this->arcs[a.start][a.end] = a.width;
        }
        this->arcNum++;
    }
}

Graph::~Graph() {

}

void Graph::insert(char v, const std::vector<Arc> &arcs) {
    this->v[vexNum] = v;
    for (auto a: arcs) {
        if (kind == UDG || kind == UDN) {
            this->arcs[a.start][a.end] = a.width;
            this->arcs[a.end][a.start] = a.width;
        } else {
            this->arcs[a.start][a.end] = a.width;
        }
        this->arcNum++;
    }
    vexNum++;
}

void Graph::show() {
    printf("  ");
    for (int i = 0; i < vexNum; i++) {
        printf("%c ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < this->vexNum; i++) {
        printf("%c ", v[i]);
        for (int j = 0; j < this->vexNum; j++) {
            printf("%d ", this->arcs[i][j]);
        }
        printf("\n");
    }
}

void Graph::remove(char v) {
    int index = 0;
    for (int i = 0; i < vexNum; i++) {
        if (this->v[i] == v) {
            index = i;
            break;
        }
    }
    for (int i = index; i < vexNum - 1; i++) {
        this->v[i] = this->v[i + 1];
    }
    for (int i = index; i < vexNum; i++) {
        for(int j = index; j < vexNum; j++) {
            this->arcs[i][j] = this->arcs[i+1][j+1];
        }
    }
    this->vexNum--;
}

/*
  首先访问一个顶点，作为出发点 --> 任选该顶点邻接且未被访问的顶点，作为新的出发点
  需要构建一个visted数组
  可以构建生成树
*/
void Graph::DFS(char v){

}

/*
  选取出发点V
  读取所有与V邻接且未被访问的点
  依次类推
*/
void Graph::BFS(char v){

}

int main() {
    const int vNum = 5;
    const int aNUm = 5;
    char nodes[vNum] = {'A', 'B', 'C', 'D', 'E'};
    std::vector<Arc> arcs;
    Arc arc1;
    Arc arc2;
    Arc arc3;
    arc1.start = 0;
    arc1.end = 1;
    arc1.width = 1;
    arcs.push_back(arc1);
    arc2.start = 1;
    arc2.end = 2;
    arc2.width = 1;
    arcs.push_back(arc2);
    arc3.start = 3;
    arc3.end = 2;
    arc3.width = 1;
    arcs.push_back(arc3);
    Graph graph(vNum, UDG, nodes, arcs);
    graph.show();
    std::cout << "<--->\n";
    std::vector<Arc> arcss;
    Arc arc4;
    arc4.start = 5;
    arc4.end = 1;
    arc4.width = 1;
    arcss.push_back(arc4);
    graph.insert('F', arcss);
    graph.show();
}



