//
// Created by lenovo on 2023/11/19.
//
#include <iostream>
#ifndef TEST3_ADJACENCYLIST_H
#define TEST3_ADJACENCYLIST_H
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

class AdjacencyList {
private:
    VNode vertices[MAX_VERTEX_NUM];
    int vexNum;
    int arcNum;
    GraphKind kind;
public:
    void GreatGraph(){
        std::cin>>this->vexNum>>this->arcNum;
        scanf("%d",&this->kind);
        for(int i = 1; i<=this->vexNum;i++){
            this->vertices[i].data = getchar();
            this->vertices[i].first = nullptr;
        }
        for(int k = 0; k< this->arcNum;k++){
            int i = 0,j = 0, width = 0;
            std::cin>>i>>j;
            Arc *arc = new Arc();
            arc->adj = j;
            arc->width = width;
            arc->next = this->vertices[i].first;
            this->vertices[i].first = arc;
        }
    }
};


#endif //TEST3_ADJACENCYLIST_H
