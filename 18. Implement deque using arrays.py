"""
Task: Deque implemented using circular array
Time Complexity: O(1) operations
Space Complexity: O(k)
"""

class ArrayDeque:
    def __init__(self, k):
        self._data = [None]*k
        self._head = 0
        self._tail = 0
        self._size = 0
        self._cap = k

    def append(self, x):
        if self._size == self._cap:
            return False
        self._data[self._tail] = x
        self._tail = (self._tail+1)%self._cap
        self._size += 1
        return True

    def appendleft(self, x):
        if self._size == self._cap:
            return False
        self._head = (self._head-1)%self._cap
        self._data[self._head] = x
        self._size += 1
        return True

    def pop(self):
        if self._size==0:
            raise IndexError("pop from empty")
        self._tail = (self._tail-1)%self._cap
        val = self._data[self._tail]
        self._data[self._tail]=None
        self._size-=1
        return val

    def popleft(self):
        if self._size==0:
            raise IndexError("popleft from empty")
        val = self._data[self._head]
        self._data[self._head]=None
        self._head = (self._head+1)%self._cap
        self._size-=1
        return val

if __name__=="__main__":
    dq=ArrayDeque(3)
    dq.append(1);dq.append(2);dq.appendleft(0)
    print(dq.pop(), dq.popleft())

# Task: Implement deque using arrays
