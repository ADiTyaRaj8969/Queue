"""
Task: Design a circular deque with fixed capacity
Time Complexity: O(1) per operation
Space Complexity: O(k)
"""

class CircularDeque:
    def __init__(self, k):
        self._data = [None]*k
        self._head = 0
        self._tail = 0
        self._size = 0
        self._cap = k

    def insertFront(self, x):
        if self._size == self._cap:
            return False
        self._head = (self._head-1) % self._cap
        self._data[self._head] = x
        self._size += 1
        return True

    def insertLast(self, x):
        if self._size == self._cap:
            return False
        self._data[self._tail] = x
        self._tail = (self._tail+1) % self._cap
        self._size += 1
        return True

    def deleteFront(self):
        if self._size == 0:
            return False
        self._data[self._head] = None
        self._head = (self._head+1) % self._cap
        self._size -= 1
        return True

    def deleteLast(self):
        if self._size == 0:
            return False
        self._tail = (self._tail-1) % self._cap
        self._data[self._tail] = None
        self._size -= 1
        return True

    def getFront(self):
        if self._size==0:
            return -1
        return self._data[self._head]

    def getRear(self):
        if self._size==0:
            return -1
        return self._data[(self._tail-1)%self._cap]

if __name__=="__main__":
    dq = CircularDeque(3)
    dq.insertLast(1)
    dq.insertLast(2)
    dq.insertFront(0)
    print(dq.getFront(), dq.getRear())

# Task: Design circular deque
