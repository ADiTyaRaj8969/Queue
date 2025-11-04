"""
Task: Queue implemented with a singly linked list
Time Complexity: enqueue/dequeue O(1)
Space Complexity: O(n)
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedListQueue:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def enqueue(self, x):
        n = Node(x)
        if not self.tail:
            self.head = self.tail = n
        else:
            self.tail.next = n
            self.tail = n
        self._size += 1

    def dequeue(self):
        if not self.head:
            raise IndexError("dequeue from empty queue")
        val = self.head.val
        self.head = self.head.next
        if not self.head:
            self.tail = None
        self._size -= 1
        return val

    def size(self):
        return self._size

if __name__ == "__main__":
    q = LinkedListQueue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    while q.size():
        print(q.dequeue())

# Task: Queue using linked list
