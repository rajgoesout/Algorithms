def parent(i):
    return i // 2


def left(i):
    return 2 * i + 1


def right(i):
    return 2 * i + 2


def max_heapify(a, i, heap_size):
    l = left(i)
    r = right(i)

    if l < heap_size and a[l] > a[i]:
        largest = l
    else:
        largest = i

    if r < heap_size and a[r] > a[largest]:
        largest = r

    if largest != i:
        a[i], a[largest] = a[largest], a[i]
        max_heapify(a, largest, heap_size)


def build_max_heap(a):
    heap_size = len(a)
    for i in range(len(a)//2 - 1, -1, -1):
        max_heapify(a, i, heap_size)


def heap_sort(a):
    build_max_heap(a)
    for i in range(len(a)-1, 0, -1):
        a[0], a[i] = a[i], a[0]
        max_heapify(a, 0, i)


if __name__ == "__main__":
    a = [5, 7, -29, 0, 178, 2, 4, 11, -2, 6, -9]
    print('Original: ', a)
    heap_sort(a)
    print('Sorted: ', a)
