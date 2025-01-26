#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

void heapifyMinHeap(int* arr, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i; 

    if (left < size && arr[left] > arr[smallest]) { 
        smallest = left;
    }

    if (right < size && arr[right] > arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMinHeap(arr, size, smallest);
    }
}

void heapifyMaxHeap(int* arr, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i; 

    if (left < size && arr[left] < arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] < arr[largest]) { 
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMaxHeap(arr, size, largest);
    }
}

void buildMinHeap(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyMinHeap(arr, size, i);
    }
}

void buildMaxHeap(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyMaxHeap(arr, size, i);
    }
}

void minHeapSort(int* arr, int size) {
    buildMinHeap(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMinHeap(arr, i, 0);
    }
}

void maxHeapSort(int* arr, int size) {
    buildMaxHeap(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMaxHeap(arr, i, 0);
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
