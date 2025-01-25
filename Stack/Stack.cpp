#include <iostream>
#include<vector>
#include"StackImp.h"
using namespace std;

// Function to print elements of an array
template <typename T>
void printArray(T* array, int size) {
    if (array == nullptr) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to print elements of a vector
template <typename T>
void printVector(const vector<T>& vec) {
    if (vec.empty()) {
        cout << "Vector is empty." << endl;
        return;
    }
    cout << "Vector elements: [" ;
    for (const T& value : vec) {
        cout << value << " ";
    }
    cout << "]" << endl;
}

int main()
{
    Stack<int> sInt;

    sInt.push(5);
    sInt.push(15);
    sInt.push(20);
    //sInt.print();

    int* arr = sInt.convertToArray();
    printArray(arr,3);

    vector<int> stackVector = sInt.convertToVector();
    printVector(stackVector);
}

