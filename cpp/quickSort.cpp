#include <iostream>
using namespace std;

int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l + 1;
    int j = h;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 50, 20, 60, 10, 30, 40 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: " << endl;
    printList(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "\nAfter sorting: " << endl;
    printList(arr, size);

    return 0;
}
