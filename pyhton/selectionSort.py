def selectionSort(arr):
    n = len(arr)
    for i in range(n - 1):
        minIdx = i
        for j in range(i + 1, n):
            if arr[j] < arr[minIdx]:
                minIdx = j
        arr[i], arr[minIdx] = arr[minIdx], arr[i]

def printArray(arr):
    for num in range(len(arr)):
        print(arr[num],end="\t")
    print()

arr = [60, 40, 50, 30, 10, 20]
print("Array before selection sort:", end=" ")
printArray(arr)
selectionSort(arr)
print("Array after selection sort:", end=" ")
printArray(arr)
