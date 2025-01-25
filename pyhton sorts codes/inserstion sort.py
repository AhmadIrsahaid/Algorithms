def insertionSort(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def printArray(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")

arr = [80, 90, 60, 30, 50, 70, 40]
print("Before sorting:")
printArray(arr)
insertionSort(arr, len(arr))
print("\nAfter sorting:")
printArray(arr)
