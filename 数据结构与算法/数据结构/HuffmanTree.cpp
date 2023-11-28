#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    int weight;
    int parent;
    int left;
    int right;
    string code;

    Tree() : weight(0), parent(-1), left(-1), right(-1) {

    }
};

typedef vector<Tree> HuffmanTree;

/**
 * 生成哈夫曼树
 * @param H 哈夫曼树
 * @param nodeNum 叶子节点数
 * @param weight 叶子节点权重值数组
 */
void creatHuffmanTree(HuffmanTree &H, int nodeNum, const int weight[]) {
    for (int i = 0; i < 2 * nodeNum - 1; i++) {
        Tree *node = new Tree();
        node->weight = weight[i];
        H.push_back(*node);
    }
    for (int i = nodeNum; i < 2 * nodeNum - 1; i++) {
        int aMin = INT_MAX;
        int bMin = INT_MAX;
        int right = -1, left = -1;
        for (int j = 0; j < i; j++) {
            if (H[j].parent != -1) {
                continue;
            }
            if (H[j].weight < aMin) {
                bMin = aMin;
                aMin = H[j].weight;
            } else if (H[j].weight < bMin) {
                bMin = H[j].weight;
            }
        }
        bool isFirst = true;
        for (int k = 0; k < i; k++) {
            if (H[k].parent != -1) {
                continue;
            }
            if (bMin == H[k].weight || aMin == H[k].weight) {
                if (isFirst) {
                    left = k;
                    isFirst = false;
                } else {
                    right = k;
                    break;
                }
            }
        }
        H[i].weight = H[left].weight + H[right].weight;
        H[i].left = left;
        H[i].right = right;
        H[left].parent = H[right].parent = i;
    }
}

/**
 * 生成哈夫曼编码
 * @param H 已构建的哈夫曼树
 * @param nodeNum 叶子节点数
 */
void creatHuffmanCode(HuffmanTree &H, int nodeNum) {
    char c;
    for (int i = 2 * nodeNum - 3; i >= 0; i--) {
        int parent = H[i].parent;
        if (H[parent].left == i) {
            c = '0';
        } else {
            c = '1';
        }
        H[i].code = H[parent].code + c;
    }
}

int main() {
    const int num = 8;
    int w[num] = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree tree;
    creatHuffmanTree(tree, num, w);
    creatHuffmanCode(tree, num);
    int t = 1;
    for (const auto &i: tree) {
        cout << t << " weight:" << i.weight << " parent:" << i.parent << " l:" << i.left << " r:"
             << i.right << " code:" << i.code << endl;
        t++;
    }
}


