#include <iostream>
#include"HeapImp.h"
using namespace std;
void inputArray(int* arr, int size) {
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

   
    int* arr = new int[size];

    inputArray(arr, size);

    
    cout << "\nOriginal array: ";
    print(arr, size);

    int choice;
    cout << "\nChoose an option:\n";
    cout << "1. Min Heap Sort\n";
    cout << "2. Max Heap Sort\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Sorting using Min Heap Sort...\n";
        minHeapSort(arr, size);
        break;
    case 2:
        cout << "Sorting using Max Heap Sort...\n";
        maxHeapSort(arr, size);
        break;
    default:
        cout << "Invalid choice!\n";
        delete[] arr; 
        return 0;
    }

    
    cout << "Sorted array: ";
    print(arr, size);

    
    delete[] arr;

    return 0;
}
