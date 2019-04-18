def binary_search(a, p, r, x):
    if r >= 1:
        q = p + (r-1)/2
        if a[q] == 1:
            return q
        elif a[q] > x:
            binary_search(a, p, q, x)
        else:
            binary_search(a, q+1, r, x)
