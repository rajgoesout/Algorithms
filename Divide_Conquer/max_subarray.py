def max_crossing_subarray(a, low, mid, high):
    left_sum = -float("inf")
    current_sum = 0
    for i in range(mid, low-1, -1):
        current_sum += a[i]
        if current_sum > left_sum:
            left_sum = current_sum
            max_left = i
    right_sum = -float("inf")
    current_sum = 0
    for j in range(mid+1, high+1):
        current_sum += a[j]
        if current_sum > right_sum:
            right_sum = current_sum
            max_right = j
    return (max_left, max_right, left_sum+right_sum)


def max_subarray(a, low, high):
    if low == high:  # base case
        return (low, high, a[low])
    else:
        mid = (low+high)//2
        left_low, left_high, left_sum = max_subarray(a, low, mid)
        right_low, right_high, right_sum = max_subarray(a, mid+1, high)
        cross_low, cross_high, cross_sum = max_crossing_subarray(
            a, low, mid, high)

        if left_sum >= right_sum and left_sum >= cross_sum:
            return (left_low, left_high, left_sum)
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)


if __name__ == '__main__':
    a = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    m = max_subarray(a, 0, len(a)-1)
    print(m)
