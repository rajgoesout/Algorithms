import time


def fib(n):
    """Naive recursive method."""
    if n <= 1:
        return n
    else:
        return fib(n-1) + fib(n-2)


def fib_top_down(n, lookup):
    """
    DP: Top down memoization approach.
    Filling on demand. Check whether value is present.
    """
    if n == 0 or n == 1:
        lookup[n] = n

    if lookup[n] == None:
        lookup[n] = fib_top_down(n-1, lookup) + fib_top_down(n-2, lookup)

    return lookup[n]


def fib_bottom_up(n):
    """
    DP: Bottom up (tabular) approach.
    Anticipate how the memory table looks like.
    Dependencies must form a DAG. fib(5) depends on fib(4) & fib(3).
    Solve subproblems in topological order.
    """
    f = [0] * (n+1)
    f[1] = 1

    for i in range(2, n+1):
        f[i] = f[i-1] + f[i-2]

    return f[n]


if __name__ == "__main__":
    n = 34

    start = time.time()
    # print(fib(n))
    # print(fib_top_down(n, [None] * (101)))
    print(fib_bottom_up(n))
    print(time.time() - start, 'seconds')
