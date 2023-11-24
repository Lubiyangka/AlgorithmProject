#include <iostream>
#include <algorithm>

#define MAX 100
using namespace std;

/**
 * 二分查找\n
 * 时间复杂度log_2(n) \n
 * n个节点的用于折半查找的判定树，表示查找失败的外部结点共有 n+1 个-->叶子结点数
 * @param arr 已排序待查数组
 * @param left 查询的区间-左
 * @param right 查询的区间-右
 * @param key 查询的值
 * @return 查找成功，返回key值所在索引，查询失败返回-1
 */
int searchBinary(const int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (key == arr[mid]) {
            return mid;
        }
        if (key > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


struct IndexTable {
    int key;
    int address;
};

struct Table {
    IndexTable index[MAX];
    int block;
    int arrLength;
};

/**
 * 索引查找
 * @param arr 待查数组
 * @param table 索引表 = 索引块最大值+索引块起始地址
 * @param key 查询关键词
 * @return 成功，返回地址\n 失败，返回-1
 */
int searchIndex(const int arr[], Table table, int key) {
    int i = 0, start, end;
    while (key > table.index[i].key && i < table.block) i++;
    if (i >= table.block) {
        return -1;
    }
    start = table.index[i].address;
    end = table.index[i + 1].address - 1;
    if (i == table.block - 1) {
        end = table.arrLength - 1;
    }
    while (start <= end) {
        if (key == arr[start]) return start;
        start++;
    }
    return -1;
}

int main() {
    const int length = 9;
    int a[length] = {1, 2, 3, 4, 5, 6, 43, 241, 78};
    sort(a, a + length);
    cout << "二分查找" << searchBinary(a, 1, 4, 43);
    Table t{};
    int arrList[length] = {22, 12, 9, 33, 42, 48, 60, 86, 53};
    t.block = 3;
    t.arrLength = length;
    int indexList[3] = {22, 48, 86};
    int j = 0;
    for (int i = 0; i < 3; i++) {
        t.index[i] = {indexList[i], j};
        j += 3;
    }
    cout << "索引顺序表查找" << searchIndex(arrList, t, 53);
}