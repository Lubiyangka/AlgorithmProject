#include <iostream>

using namespace std;
/**
 * 二分查找\n
 * 时间复杂度log_2(n)\n
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

int main() {
    int a[8] = {1,2,3,4,5,6,43,241};
    cout<<searchBinary(a, 1, 4, 43);
}