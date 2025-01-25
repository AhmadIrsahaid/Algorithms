def insertionSort(a, b):
    for i in range(1, b):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j = j - 1
        a[j + 1] = key

def printt(a, b):
    for i in range(b):
        print(a[i])

arr = [31, 41, 59, 26, 31, 58]

n = len(arr)

insertionSort(arr, n)

printt(arr, n)
