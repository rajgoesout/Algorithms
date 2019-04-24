def partition(a, p, r):
    x = a[r]  # pivot element
    i = p - 1
    for j in range(p, r):
        if a[j] <= x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i+1], a[r] = a[r], a[i+1]

    return i+1


def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q-1)
        quick_sort(a, q+1, r)


if __name__ == "__main__":
    a = [5, 7, -29, 0, 178, 2, 4, 11, -2, 6, -9]
    print('Original: ', a)
    quick_sort(a, 0, len(a)-1)
    print('Sorted: ', a)
