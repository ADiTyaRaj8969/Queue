"""
Task: Queue wrapper with a maximum size and safe enqueue
Time Complexity: O(1)
Space Complexity: O(k)
"""

class BoundedQueue:
    def __init__(self, k):
        self._data = [None]*k
        self._head = 0
        self._tail = 0
        self._size = 0
        self._cap = k

    def enqueue(self, x):
        if self._size == self._cap:
            return False
        self._data[self._tail] = x
        self._tail = (self._tail+1) % self._cap
        self._size += 1
        return True

    def try_enqueue(self, x):
        # safe enqueue that returns a tuple (success, dropped_item)
        if self._size < self._cap:
            self.enqueue(x)
            return True, None
        else:
            dropped = self._data[self._head]
            self.dequeue()
            self.enqueue(x)
            return True, dropped

    def dequeue(self):
        if self._size == 0:
            raise IndexError("dequeue from empty queue")
        val = self._data[self._head]
        self._data[self._head] = None
        self._head = (self._head+1) % self._cap
        self._size -= 1
        return val

if __name__ == "__main__":
    q = BoundedQueue(2)
    print(q.enqueue(1))
    print(q.enqueue(2))
    print(q.try_enqueue(3))
    while q._size>0:
        print(q.dequeue())

# Task: Queue with max size
