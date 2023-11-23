#include <bits/stdc++.h>

using namespace std;

struct Node {
    int coefficient;
    int exponent;
};

struct NodeList {
    Node data;
    NodeList *next;
};

void input(NodeList *L) {
    NodeList *p = L;
    char c;
    do {
        NodeList *node = new NodeList();
        scanf("%d %d", &node->data.coefficient, &node->data.exponent);
        node->next = nullptr;
        p->next = node;
        p = node;
    } while (c = getchar() != '\n');
}

void output(NodeList *L) {
    NodeList *p;
    for (p = L->next; p != nullptr; p = p->next) {
        if (p->data.exponent != 0) {
            cout << p->data.coefficient * p->data.exponent << " " << p->data.exponent - 1;
        } else {
            if (L->next->next == nullptr) {
                cout << p->data.coefficient * p->data.exponent << " 0";
            } else continue;
        }
        if (p->next != nullptr) {
            cout << " ";
        }
    }
}

int main() {
    NodeList *nodeList = new NodeList();
    input(nodeList);
    output(nodeList);
}