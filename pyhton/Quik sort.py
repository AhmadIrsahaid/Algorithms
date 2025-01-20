def partition(arr, l, h):
    pivot = arr[l]
    i = l + 1
    j = h
    while True:
        while i <= j and arr[i] <= pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i >= j:
            break
        arr[i], arr[j] = arr[j], arr[i]
    arr[l], arr[j] = arr[j], arr[l]
    return j

def quickSort(arr, l, h):
    if l < h:
        p = partition(arr, l, h)
        quickSort(arr, l, p - 1)
        quickSort(arr, p + 1, h)

def printList(arr):
    print(*arr)

arr = [50,20,60,10,30,40]
print("before sorting : ")
printList(arr)
quickSort(arr, 0, len(arr) - 1)
print("\nafter sorting : ")

printList(arr)
