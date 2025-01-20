#include <iostream>
using namespace std;
void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr, int L, int R);
void print(int* arr, int n);
int main()
{
    int arr[] = { 30,20,40,5,90,80,10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "the array before sorted : ";
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "the array after sorted : ";
    print(arr, n);

}
void merge(int* arr, int l, int m, int r) {
    int i, j;
    int k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];

    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int* arr, int L, int R) {
    if (L < R) {
        int m = L + (R - L) / 2;
        mergeSort(arr, L, m);
        mergeSort(arr, m+1, R);
        merge(arr, L, m, R);
    }
}

void print(int* arr, int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}