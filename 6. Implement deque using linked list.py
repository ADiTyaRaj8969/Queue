"""
Task: Implement deque using a doubly linked list
Time Complexity: O(1) per operation
Space Complexity: O(n)
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class LinkedDeque:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def append(self, x):
        n = Node(x)
        if not self.tail:
            self.head = self.tail = n
        else:
            self.tail.next = n
            n.prev = self.tail
            self.tail = n
        self._size += 1

    def appendleft(self, x):
        n = Node(x)
        if not self.head:
            self.head = self.tail = n
        else:
            n.next = self.head
            self.head.prev = n
            self.head = n
        self._size += 1

    def pop(self):
        if not self.tail:
            raise IndexError("pop from empty deque")
        val = self.tail.val
        self.tail = self.tail.prev
        if self.tail:
            self.tail.next = None
        else:
            self.head = None
        self._size -= 1
        return val

    def popleft(self):
        if not self.head:
            raise IndexError("popleft from empty deque")
        val = self.head.val
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.tail = None
        self._size -= 1
        return val

    def size(self):
        return self._size

if __name__ == "__main__":
    dq = LinkedDeque()
    dq.append(1)
    dq.appendleft(0)
    dq.append(2)
    print(dq.pop())
    print(dq.popleft())

# Task: Implement deque using linked list
