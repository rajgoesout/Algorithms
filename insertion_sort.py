def insertion_sort(a):
    for j in range(1, len(a)):
        key = a[j]
        # insert a[j] into te sorted sequence a[i..j-1]
        i = j-1
        while i >= 0 and a[i] > key:
            a[i+1] = a[i]
            i = i-1
        a[i+1] = key


if __name__ == '__main__':
    a = [5, 7, -29, 0, 178, 2, 4, 11, -2, 6, -9]
    print("Original array: ", a)
    insertion_sort(a)
    print("Sorted array: ", a)
