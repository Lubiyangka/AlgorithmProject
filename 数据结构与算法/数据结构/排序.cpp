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
    int guard = partition(num, left, right);
    quickSort(num, left, guard - 1);
    quickSort(num, guard + 1, right);
}

/**
 * 冒泡
 * @param num
 * @param length
 */
void bubbleSort(int num[], int length) {
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j + 1] < num[j]) {
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
    for (int i = 1; i < length; i++) {
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
        for (int j = i; j < length; j++) {
            if (num[j] < num[k]) {
                k = j;
            }
        }
        swap(num, i, k);
    }
}

/**
 * 归并操作
 * @param num
 * @param left
 * @param mid
 * @param right
 */
void merge(int num[], int left, int mid, int right) {
    int temp[right + 1 - left];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (num[i] <= num[j]) {
            temp[k++] = num[i++];
        } else {
            temp[k++] = num[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = num[i++];
    }
    while (j <= right) {
        temp[k++] = num[j++];
    }
    for (int m = 0; m < right + 1 - left; m++) {
        num[left + m] = temp[m];
    }
}

/**
 * 归并
 * @param num
 * @param left
 * @param right
 */
void mergeSort(int num[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(num, left, mid);
    mergeSort(num, mid + 1, right);
    merge(num, left, mid, right);
}

/**
 * 计数排序
 * @param num
 * @param length
 */
void countSort(int num[], int length) {
    int max = 0;
    for (int i = 0; i < length; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }
    int temp[max + 1];
    for (int &i: temp) {
        i = 0;
    }
    for (int i = 0; i < length; i++) {
        temp[num[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max + 1; i++) {
        for (int j = 0; j < temp[i]; j++, k++) {
            num[k] = i;
        }
    }
}



int main() {
    //待排序数组
    int arr[10] = {23, 14, 35, 65, 43, 76, 34, 42, 31, 56};
    int o = 0;
    cin >> o;
    switch (o) {
        case 0:
            quickSort(arr, 0, 9);
            break;
        case 1:
            bubbleSort(arr, 10);
            break;
        case 2:
            selectSort(arr, 10);
            break;
        case 3:
            insertSort(arr, 10);
            break;
        case 4:
            mergeSort(arr, 0, 9);
            break;
        case 5:
            countSort(arr,10);
            break;
        default:
            break;
    }

    for (int i: arr) {
        cout << i << " ";
    }
}
