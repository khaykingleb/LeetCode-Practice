from typing import List
import numpy as np


def merge(arr: List[int], left: int, middle: int, right: int):
    n_left = middle - left + 1
    n_right = right - middle

    subarr_left = []
    subarr_right = []

    for i in range(n_left):
        subarr_left.append(arr[left + i])

    for j in range(n_right):
        subarr_right.append(arr[middle + j + 1])

    subarr_left.append(np.infty)
    subarr_right.append(np.infty)

    i = 0
    j = 0
    k = left

    while k <= right:
        if subarr_left[i] <= subarr_right[j]:
            arr[k] = subarr_left[i]
            i += 1
        else:
            arr[k] = subarr_right[j]
            j += 1

        k += 1


def merge_sort(arr: List[int], left: int, right: int):
    if left < right:
        middle = (left + right) // 2
        merge_sort(arr, left, middle)
        merge_sort(arr, middle + 1, right)
        merge(arr, left, middle, right)


def sort_array(arr: List[int]) -> List[int]:
    merge_sort(arr, 0, len(arr) - 1)
    return arr


n = input()
nums = []

for _ in range(int(n)):
    nums.append(int(input()))

nums_new = sort_array(nums)

print(*nums_new)
