#include <iostream>
#include<algorithm>
using namespace std;
void selectionSort(int* arr, int n) {

	int mianIdx;
	for (int i = 0; i < n - 1; i++) {
		mianIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[mianIdx]) {
				mianIdx = j;
				
			}
		}
		swap(arr[mianIdx], arr[i]);
	}
}
void print(int* arr, int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 60,40,50,30,10,20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Array before selection sort : ";
	print(arr, n);
	selectionSort(arr, n);
	cout << "Array after selection sort : ";
	print(arr, n);

}

