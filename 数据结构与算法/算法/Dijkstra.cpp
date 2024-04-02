/**
 * @author John-Six
 */
//权值不能为负
enum typeGraph {
    DG, WG, UDG, UWG
};

#include <iostream>

using namespace std;
#define MAX_NUM 100

struct Graph {
    int type;
    int numNode;
    int numVax;
    char node[MAX_NUM];
    int vax[MAX_NUM][MAX_NUM];

    Graph(int node, int vax) : numNode(node), numVax(vax) {}

};

Graph graph{5, 7};
//到最短路最后一个点的距离
int D[5];
//是否遍历过
bool final[5];
//记录该点的前驱
char P[5];

void init() {
    char c[5] = {'a', 'b', 'c', 'd', 'e'};
    int d[5][5] = {{0,       6,       3, MAX_NUM, MAX_NUM},
                   {6,       0,       2, 5,       MAX_NUM},
                   {3,       2,       2, 3, 4},
                   {MAX_NUM, 5,       3, 0, 2},
                   {MAX_NUM, MAX_NUM, 4, 2, 0}};
    for (int i = 0; i < graph.numNode; i++) {
        for (int j = 0; j < graph.numNode; j++) {
            graph.vax[i][j] = d[i][j];
        }
    }
    for (int i = 0; i < graph.numNode; i++) {
        graph.node[i] = c[i];
    }
}

int findNodeIndex(const char node) {
    for (int i = 0; i < graph.numNode; i++) {
        if (graph.node[i] == node) {
            return i;
        }
    }
    return -1;
}

void shortestPathDIJ(char v0) {
    int index = findNodeIndex(v0);
    for (int i = 0; i < graph.numNode; i++) {
        final[i] = false;
        D[i] = graph.vax[index][i];
        P[i] = '#';
        if (D[i] < MAX_NUM) {
            P[i] = v0;
        }
    }
    final[index] = true;
    P[index] = '#';
    for (int i = 1; i < graph.numNode; i++) {
        int min = MAX_NUM+1;
        int v = index;
        for(int j = 0 ; j < graph.numNode; j++){
            if(!final[j] && D[j] < min){
                min = D[j];
                v = j;
            }
        }
        final[v] = true;
        for(int j = 0; j < graph.numNode; j++){
            if(!final[j] && min + graph.vax[v][j] < D[j]){
                D[j] = min + graph.vax[v][j];
                P[j] = graph.node[v];
            }
        }
    }
}

void out(){
    for(int i = 0;i < graph.numNode; i++){
        cout<<D[i]<<" "<<graph.node[i];
        char pre = P[i];
        while(pre != '#'){
            cout<<"<-"<<pre;
            pre = P[findNodeIndex(pre)];
        }
        printf("\n");
    }
}

int main() {
    init();
    shortestPathDIJ('a');
    out();
}