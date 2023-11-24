#include <iostream>

using namespace std;

/*
插入排序，快速排序，选择排序，归并排序，基数排序
*/
/**
 * 交换
 * @param a
 * @param i
 * @param j
 */
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/**
 * 快排的哨兵
 * @param list
 * @param left
 * @param right
 * @return
 */
int partition(int list[], int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && list[j] >= list[left]) {
            j--;
        }
        while (i < j && list[i] <= list[left]) {
            i++;
        }
        swap(list, i, j);
    }
    swap(list, i, left);
    return i;
}
/**
 * 快排
 * @param num
 * @param left
 * @param right
 */
void quickSort(int num[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(num, left, right);
    quickSort(num, left, pivot - 1);
    quickSort(num, pivot + 1, right);
}

/**
 * 冒泡
 * @param num
 * @param length
 */
void bubbleSort(int num[], int length) {
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num, j, j + 1);
            }
        }
    }
}

/**
 * 插入
 * @param num
 * @param length
 * @return
 */

void insertSort(int num[], int length) {
    for (int i = 0; i < length; i++) {
        int k = num[i];
        int j = i - 1;
        while (j >= 0 && num[j] > k) {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = k;
    }
}

/**
 * 选择
 * @param num
 * @param length
 */
void selectSort(int num[], int length) {
    for (int i = 0; i < length; i++) {
        int k = i;
        for (int j = i + 1; j < length; j++) {
            if (num[j] < num[k]) {
                k = j;
            }
        }
        swap(num, i, k);
    }
}

int main() {
    //待排序数组
    int arr[10] = {23, 14, 35, 65, 43, 76, 34, 42, 31, 56};
    quickSort(arr,0,9);
//    bubbleSort(arr,10);
//    selectSort(arr,10);
//    insertSort(arr, 10);
    for (int i: arr) {
        cout << i << " ";
    }
}
