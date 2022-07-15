#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pythonds.basic import Stack
from pythonds.basic.queue import Queue


# 用数组实现栈结构
class ArrayStack(object):
    def __init__(self, init_size):
        """
        _size表示队列内元素的数目；
        _arr 是一个固定容量的列表实例
        """
        if init_size < 0:
            raise Exception('The init size is less than 0')
        self._size = 0
        self._arr = [None] * init_size

    def top(self):
        # 取出目前stack中最新的元素
        if self._size == 0:
            return None
        return self._arr[self._size - 1]

    def push(self, obj):
        # 进栈
        if self._size == len(self._arr):
            raise Exception('The queue is full')
        self._arr[self._size] = obj
        self._size += 1

    def pop(self):
        # 出栈
        if self._size == 0:
            raise Exception('The queue is empty')
        self._size -= 1
        return self._arr[self._size]


class ArrayQueue:
    def __init__(self, init_size):
        if init_size == 0:
            raise Exception('The init_size is less than 0')
        self._array = [None] * init_size
        self._size = 0
        self._first = 0
        self._last = 0

    def top(self):
        # 返回队列最新元素
        if self._size == 0:
            return None
        return self._array[self._first]

    def push(self, obj):
        if self._size == len(self._array):
            raise Exception('The queue is full')
        self._array[self._last] = obj
        # 此处取模操作是为了第一位元素处于数组末端的情况
        # self._last = (self._last + 1) % len(self._array)
        self._last = 0 if self._last == len(self._array) - 1 else self._last + 1
        self._size += 1

    def poll(self):
        # 返回并删除首个元素
        if self._size == 0:
            return None
        result = self._array[self._first]
        self._size -= 1
        self._first = 0 if self._first == len(self._array) - 1 else self._first + 1
        return result


# 用数组实现队列结构
class ArrayQueue2:
    DEFAULT_SIZE = 10

    def __init__(self):
        """
        _front:队列第一个元素的索引
        _size:队列内元素的数目
        _data:固定容量的列表实例
        """
        self._front = 0
        self._size = 0
        self._data = [None] * ArrayQueue2.DEFAULT_SIZE

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def is_full(self):
        return self._size == len(self._data)

    def top(self):
        return self._data[self._front]

    def push(self, arg):
        if self.is_full():
            raise Exception('array is full')
        end = (self._front + self._size) % len(self._data)
        self._data.insert(end, arg)
        self._size += 1

    def poll(self):
        if self.is_empty():
            raise Exception('array is empty')
        first_index = self._front
        result = self._data[first_index]
        # 此处取模操作是为了第一位元素处于数组末端的情况
        self._front = (self._front + 1) % len(self._data)
        self._data[first_index] = None
        self._size -= 1
        return result


# 实现一个特殊的栈，在实现栈的基础上，可返回栈内最小值。要求 pop、push、getMin 操作的时间复杂度都是O(1)
class GetMinStack():
    def __init__(self):
        self.stack_data = Stack()
        self.stack_min = Stack()

    def push(self, obj):
        if self.stack_min.isEmpty():
            self.stack_min.push(obj)
        else:
            if obj <= self.get_min():
                self.stack_min.push(obj)
            else:
                self.stack_min.push(self.get_min())
        self.stack_data.push(obj)

    def pop(self):
        if self.stack_data.isEmpty():
            raise Exception('Your stack is empty')
        self.stack_min.pop()
        return self.stack_data.pop()

    def get_min(self):
        if self.stack_min.isEmpty():
            raise Exception('Your stack is empty')
        return self.stack_min.peek()


# 只用队列实现栈
class TwoQueuesStack:
    def __init__(self):
        self.queue_data = Queue()
        self.queue_help = Queue()

    def push(self, obj):
        self.queue_data.enqueue(obj)

    def peek(self):
        if self.queue_data.isEmpty():
            raise Exception('Stack is empty')
        while self.queue_data.size() > 1:
            self.queue_help.enqueue(self.queue_data.dequeue())
        result = self.queue_data.dequeue()
        self.queue_help.enqueue(result)
        self.swap()
        return result

    def pop(self):
        if self.queue_data.isEmpty():
            raise Exception('Stcak is empty')
        while self.queue_data.size() > 1:
            self.queue_help.enqueue(self.queue_data.dequeue())
        result = self.queue_data.dequeue()
        self.swap()
        return result

    def swap(self):
        self.queue_data, self.queue_help = self.queue_help, self.queue_data


# 只用栈实现队列
class TwoStacksQueue:
    def __init__(self):
        self.stack_push = Stack()
        self.stack_pop = Stack()

    def push(self, obj):
        self.stack_push.push(obj)

    def poll(self):
        if self.stack_pop.isEmpty() and self.stack_push.isEmpty():
            raise Exception('Queue is empty')
        elif self.stack_pop.isEmpty():
            while not self.stack_push.isEmpty():
                self.stack_pop.push(self.stack_push.pop())
        return self.stack_pop.pop()

    def peek(self):
        if self.stack_pop.isEmpty() and self.stack_push.isEmpty():
            raise Exception('Queue is empty')
        elif self.stack_pop.isEmpty():
            while not self.stack_push.isEmpty():
                self.stack_pop.push(self.stack_push.pop())
        return self.stack_pop.peek()


if __name__ == '__main__':
    pass
