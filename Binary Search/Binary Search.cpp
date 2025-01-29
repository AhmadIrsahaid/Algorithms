#include <iostream>
#include"BSImpl.h"
using namespace std;
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x;
    cout << "enter a key plz" << endl;
    cin >> x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearchIterative(arr, 0, n - 1, x);
    if (result == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result;
    cout << "\n==================================================" << endl;

    int arr2[] = { 2, 3, 4, 10, 40 };
    int query = 2;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = binarySearchRecursive(arr2, 0, n2 - 1, query);
    if (result2 == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result2;
    return 0;
}

