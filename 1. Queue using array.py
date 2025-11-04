"""
Task: Simple queue implementation using a fixed-size array (circular buffer)
Time Complexity: enqueue/dequeue O(1)
Space Complexity: O(k)
"""

class CircularQueue:
    def __init__(self, k: int):
        self._data = [None] * k
        self._head = 0
        self._tail = 0
        self._size = 0
        self._cap = k

    def enqueue(self, x):
        if self._size == self._cap:
            return False
        self._data[self._tail] = x
        self._tail = (self._tail + 1) % self._cap
        self._size += 1
        return True

    def dequeue(self):
        if self._size == 0:
            raise IndexError("dequeue from empty queue")
        val = self._data[self._head]
        self._data[self._head] = None
        self._head = (self._head + 1) % self._cap
        self._size -= 1
        return val

    def front(self):
        if self._size == 0:
            raise IndexError("front from empty queue")
        return self._data[self._head]

    def rear(self):
        if self._size == 0:
            raise IndexError("rear from empty queue")
        return self._data[(self._tail - 1) % self._cap]

    def size(self):
        return self._size


if __name__ == "__main__":
    q = CircularQueue(3)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(q.front(), q.rear())
    q.dequeue()
    q.enqueue(4)
    while q.size() > 0:
        print(q.dequeue())

# Task: Queue using array (circular buffer)
