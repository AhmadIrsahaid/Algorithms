def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = arr[l:m + 1]
    R = arr[m + 1:r + 1]

    i = j = 0
    k = l

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, L, R):
    if L < R:
        m = (L + R) // 2
        mergeSort(arr, L, m)
        mergeSort(arr, m + 1, R)
        merge(arr, L, m, R)

def printArray(arr):
    for num in arr:
        print(num, end="\t")
    print()

if __name__ == "__main__":
    arr = [30, 20, 40, 5, 90, 80, 10]
    print("The array before sorted : ", end="")
    printArray(arr)
    mergeSort(arr, 0, len(arr) - 1)
    print("The array after sorted : ", end="")
    printArray(arr)
