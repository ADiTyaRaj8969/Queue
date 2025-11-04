"""
Task: Implement deque using Python lists (inefficient pop(0))
Time Complexity: append/pop O(1) amortized; pop(0)/insert(0) O(n)
Space Complexity: O(n)
"""

class SimpleDeque:
    def __init__(self):
        self._data = []

    def append(self, x):
        self._data.append(x)

    def appendleft(self, x):
        self._data.insert(0, x)

    def pop(self):
        if not self._data:
            raise IndexError("pop from empty deque")
        return self._data.pop()

    def popleft(self):
        if not self._data:
            raise IndexError("pop from empty deque")
        return self._data.pop(0)

if __name__ == "__main__":
    dq = SimpleDeque()
    dq.append(1)
    dq.appendleft(0)
    dq.append(2)
    print(dq.pop())
    print(dq.popleft())

# Task: Implement deque using lists
