#include<iostream>

using namespace std;

int BinarySearch(const int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (key == arr[mid]) {
            return mid;
        }
        if (key > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid + 1;
        }
    }
    return -1;
}
