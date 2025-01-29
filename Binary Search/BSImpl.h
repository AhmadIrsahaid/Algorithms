#pragma once
int binarySearchIterative(int *arr , int left ,int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
            
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        
        if (arr[mid] > x)
            return binarySearchRecursive(arr, low, mid - 1, x);

  
        return binarySearchRecursive(arr, mid + 1, high, x);
    }
    return -1;
}
