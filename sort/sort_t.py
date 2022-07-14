#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import operator

"""
选择排序
------------
* 首先在乱序序列中找到最小的元素，存放在序列的起始位置，然后在剩余序列
* 中继续寻找最小元素，放在已排序列末尾，...以此类推，直到所有元素均排
* 列完毕就可以了
------------
* 第一次遍历 0-N上的数，找到最小值放在 0位置上，
* 第二次遍历 1-N上的数，找到最小值放在1位置上，
"""


def selection_sort(arr):
    # 每次交换
    if len(arr) < 2:
        return
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[i]:
                arr[i], arr[j] = arr[j], arr[i]


def selection_sort2(arr):
    # 记录最小序号，最后交换
    if len(arr) < 2:
        return
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        if min_index != i:
            arr[min_index], arr[i] = arr[i], arr[min_index]


'''
冒泡排序
-------
* 重复扫描待排序序列，并比较每一对相邻的元素，当该对元素顺序不正确时
* 进行交换。一直重复这个过程，直到没有任何两个相邻的元素可以交换，就
表明完成了排序。每次扫描会排好最大的数
'''


def bobble_sort(arr):
    if len(arr) < 2:
        return
    for i in range(len(arr)):
        for j in range(len(arr) - i - 1):
            if arr[j + 1] < arr[j]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


'''
插入排序
----
* 将第一个元素看做已排序，第二个元素及以后未排序
* 在未知元素中取第一个元素，插入到已知的元素序列中。将未排序的第一个元素与已排序的最后一个元素进行比较
* ，如果未知<已知，则交换位置，然后再与交换未知后的未的前一个元素进行比较，直到不能交换为止，此时插入
    元素，经过这样操作后，已知元素的顺序，都是由小到大排列de
* 重复操作，每插入一次，已排序元素长度+1，未排序元素长度-1
'''


def insertion_sort(arr):
    if len(arr) < 2:
        return
    for i in range(1, len(arr)):
        current_index = i
        while arr[current_index] < arr[current_index - 1] and (current_index - 1) >= 0:
            arr[current_index - 1], arr[current_index] = arr[current_index], \
                                                         arr[current_index - 1]
            current_index = current_index - 1


'''
归并排序
---------
* 使用递归过程将左右两个子数组排好，然后使用外排方式将整体排好
* 时间复杂度O(n*logn),空间复杂度为O(n)

* merge_sort 会返回临时数组
* merge_sort2 不会返回临时数组,教程写法
'''


def merge_sort(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    left_arr = merge_sort(arr[:mid])
    right_arr = merge_sort(arr[mid:])
    return merge(left_arr, right_arr)


def merge(left_arr, right_arr):
    # 将两个排过序的两个列表进行合并并排序
    left_index, right_index, result = 0, 0, list()
    while left_index < len(left_arr) and right_index < len(right_arr):
        # 如果左边的数大于右边的数，就将左边的数先添加到result中，再继续比较（合并的R、L已经排过序）
        # 如果如果右边的数大于左边的数，就将右边的数先添加到result中，再继续比较（合并的R、L已经排过序）
        if left_arr[left_index] <= right_arr[right_index]:
            result.append(left_arr[left_index])
            left_index += 1
        else:
            result.append(right_arr[right_index])
            right_index += 1
    # 因为当 left_index < len(left_arr)  或者 right_index < len(right_arr)时，跳出while循环，且每次循环只处理一个列表里的内容，
    # 所以其中有一个列表内容会先全部加入result中，另一个列表还剩内容未加进result中。对未处理完的列表，直接加入result中
    # result = result + left_arr[left_index:] + right_arr[right_index:]
    result += right_arr[right_index:] if left_index == len(left_arr) else left_arr[left_index:]

    return result


def merge2(arr, left, mid, right):
    left_index = left
    right_index = mid + 1
    result = []
    sum = 0
    while left_index <= mid and right_index <= right:
        if arr[left_index] <= arr[right_index]:
            sum += arr[left_index] * (right - right_index + 1)
            result.append(arr[left_index])
            left_index += 1
        else:
            result.append(arr[right_index])
            right_index += 1
    while left_index <= mid:
        result.append(arr[left_index])
        left_index += 1
    while right_index <= right:
        result.append(arr[right_index])
        right_index += 1
    arr[left:right + 1] = result
    return sum


def merge_sort2(arr, left, right):
    '''
    :param arr: 无序数组
    :param left: 第一个元素的下标
    :param right: 最后一个元素的下标
    :param sum: 返回值为小和作准备，若只是排序，可去掉返回值
    '''
    # 这里用递归的思想,将整个归并看成只需要分别归并列表的左边与右边,当左边和右边都变成有序的之后在进行整个列表的归并
    if left == right:
        return 0
    mid = (left + right) // 2
    # 归并左边
    sum_left = merge_sort2(arr, left, mid)
    # 归并右边
    sum_right = merge_sort2(arr, mid + 1, right)
    # 归并整个列表
    sum_merge = merge2(arr, left, mid, right)
    return sum_left + sum_right + sum_merge


'''
小和问题
-----
分治法 
#TODO：除了使用返回值方法还有其他方法吗
'''


def small_sum(arr, left, right):
    if left == right:
        return 0
    return merge_sort2(arr, left, right)


'''
* 递归求最大值:分置思想，分别求左边和右边的最大值，左边和右边最大值的最大值为整体最大值
'''


def get_max(arr, l, r):
    if l == r:
        return arr[l]
    mid = (l + r) // 2
    max_left = get_max(arr, l, mid)
    max_right = get_max(arr, mid + 1, r)
    return max(max_left, max_right)


'''
荷兰国旗问题
'''


def partition(arr, left, right, num):
    less = left - 1
    more = right + 1
    cur = left
    while cur < more:
        if arr[cur] < num:
            less += 1
            arr[less], arr[cur] = arr[cur], arr[less]
            cur += 1
        elif arr[cur] > num:
            more -= 1
            arr[cur], arr[more] = arr[more], arr[cur]
        else:
            cur += 1
    return less + 1, more - 1


'''
快速排序
'''


def quick_sort(arr, left, right):
    if left < right:
        left_index, right_index = partition(arr, left, right, arr[right])
        quick_sort(arr, left, left_index - 1)
        quick_sort(arr, right_index + 1, right)


# 堆排序，堆是一棵完全二叉树
def heap_sort(arr):
    if len(arr) < 2:
        return
    # 建立大根堆
    for i in range(len(arr)):
        heap_insert(arr, i)
        print(i, ' ', arr)
    # 依次取出最大值放在数组后面
    size = len(arr) - 1
    arr[0], arr[size] = arr[size], arr[0]
    while size > 0:
        heapify(arr, 0, size)
        size -= 1
        arr[0], arr[size] = arr[size], arr[0]


# 把数组变为大根堆，往上浮
def heap_insert(arr, index):
    while arr[index] > arr[(index - 1) // 2] and (index - 1) // 2 >= 0:
        arr[index], arr[(index - 1) // 2] = arr[(index - 1) // 2], arr[index]
        index = (index - 1) // 2


# 大根堆中某个数字发生变化，重新调整为大根堆。把当前数与子节点比较，往下沉
def heapify(arr, index, size):
    left = index * 2 + 1
    while left < size:
        largest = left + 1 if left + 1 < size and arr[left + 1] > arr[left] else left
        largest = largest if arr[largest] > arr[index] else index
        if largest == index:
            break
        arr[largest], arr[index] = arr[index], arr[largest]
        index = largest
        left = index * 2 + 1


# 给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度O(N)，不能使用基于比较的排序。
def max_gap(arr):
    if len(arr) < 2:
        return 0
    size = len(arr)
    min_t = min(arr)
    max_t = max(arr)

    if min_t == max_t:
        return 0
    maxs = [max_t] * (size + 1)
    mins = [min_t] * (size + 1)
    has_num = [False] * (size + 1)
    for i in range(size):
        bid = bucket(arr[i], size, min_t, max_t)
        mins[bid] = min(mins[bid], arr[i]) if has_num[bid] else arr[i]
        maxs[bid] = max(maxs[bid], arr[i]) if has_num[bid] else arr[i]
        has_num[bid] = True
    result = 0
    last_max = maxs[0]
    for i in range(1, size + 1):
        if has_num[i]:
            result = max(result, mins[i] - last_max)
            last_max = maxs[i]

    return result


def bucket(num, size, min_t, max_t):
    return int((num - min_t) * size / (max_t - min_t))


# --------------------------------------测试分割线------------------------------------
def generate_random_arr(size, value):
    arr = []
    for i in range(size):
        arr.append(random.random() * (value + 1) - random.random() * value)

    return arr


def right_sort(arr):
    arr.sort()
    return arr


def is_true(times, value, size, func):
    success = True
    for j in range(times):
        arr1 = generate_random_arr(size, value)
        arr2 = arr1.copy()
        arr3 = arr1.copy()
        func(arr2)
        right_sort(arr3)
        if not operator.eq(arr2, arr3):
            success = False
            print(arr1)
            break
    print('NICE' if success == True else 'SHIT')


if __name__ == '__main__':
    arr = [7, 8, -9, 40, -4, 98, 40, 5, 9, 10]
    # arr = [2, 8, 4,3]
    arr = [ 1, 3, 4, 2, 5, 9,-5]
    # merge_sort(arr, 0, len(arr) - 1)
    res = max_gap(arr)
    print(arr)
    print(res)
