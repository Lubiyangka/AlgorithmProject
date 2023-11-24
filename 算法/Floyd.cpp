//#include<iostream>
//
//using namespace std;
//
//int BinarySearch(const int arr[], int left, int right, int key) {
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (key == arr[mid]) {
//            return mid;
//        }
//        if (key > arr[mid]) {
//            left = mid + 1;
//        } else {
//            right = mid + 1;
//        }
//    }
//    return -1;
//}
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

int D[5][5];
//Floyd算法输出判断矩阵
bool flag[5][5][5];

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

void shortestPathFloyd() {
    for(int i = 0; i < graph.numNode; i++){
        for(int j = 0; j < graph.numNode; j++){
            D[i][j] = graph.vax[i][j];
            for(int k = 0; k < graph.numNode;k++){
                flag[i][j][k] = false;
            }
            if(D[i][j] < MAX_NUM){
                flag[i][j][i] = flag[i][j][j] = true;
            }
        }
    }
    for(int i = 0; i < graph.numNode; i++){
        for(int j = 0; j < graph.numNode; j++){
            for(int k = 0; k < graph.numNode;k++){
                if(D[j][i]+D[i][k] < D[j][k]){
                    D[j][k] = D[j][i]+D[i][k];
                    for(int v = 0; v < graph.numNode;v++){
                        flag[j][k][v] = (flag[j][i][v]||flag[i][k][v]);
                    }
                }
            }
        }
    }
}

int main() {
    init();
}git 