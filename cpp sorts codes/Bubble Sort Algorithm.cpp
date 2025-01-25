#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int *arr , int n) {

    bool flag = true;
    int counter = 0; // to count number of pass 

    for (int i = 0; i < n - 1 ; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
            counter++;
        }
        if (flag) break;
    }

    cout << "number of rounds : " << counter << endl;

}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {100,60,20,50,30,90};
    int size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, size);
    printArray(arr, size);

}
