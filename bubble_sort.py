def bubble_sort(a):
    n = len(a)
    for i in range(n):
        for j in range(n-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]


if __name__ == "__main__":
    # a = [18923, 28, 24, 1, 2, 83, -32, 2, 0, 167, 3, 9]
    a = [5, 7, -29, 0, 178, 2, 4, 11, -2, 6, -9]
    print('Original: ', a)
    bubble_sort(a)
    print('Sorted: ', a)
