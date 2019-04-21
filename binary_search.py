import sys


def binary_search(a, value):
    result = -1
    down = 0
    up = len(a)
    i = (up - down + 1) // 2
    while down < i < up:
        if a[i] == value:
            result = i
            break
        elif a[i] > value:
            up = i
            i = i - (up + 1 - down) // 2
        elif a[i] < value:
            down = i
            i = i + 1 + len(a[down+1:up]) // 2

    return result


if __name__ == "__main__":
    if len(sys.argv) > 1:
        value = int(sys.argv[1])
    else:
        value = -2
    a = [-29, -9, -2, 0, 2, 4, 5, 6, 7, 11, 178]
    print('a =', a)
    index = binary_search(a, value)
    if index != -1:
        # print('a[' + str(index) + '] = ' + str(a[index]))
        print(f'a[{index}] = {a[index]}')
    else:
        print(f"{value} doesn't exist in this array")
