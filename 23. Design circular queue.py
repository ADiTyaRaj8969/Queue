"""
Task: Design circular queue with fixed capacity (duplicate of earlier)
Time Complexity: O(1)
Space Complexity: O(k)
"""

class CircularQueue:
    def __init__(self, k):
        self.data = [None]*k
        self.head = 0
        self.tail = 0
        self.cap = k
        self.sz = 0

    def enqueue(self, x):
        if self.sz == self.cap:
            return False
        self.data[self.tail] = x
        self.tail = (self.tail+1)%self.cap
        self.sz += 1
        return True

    def dequeue(self):
        if self.sz == 0:
            raise IndexError('dequeue from empty')
        val = self.data[self.head]
        self.data[self.head] = None
        self.head = (self.head+1)%self.cap
        self.sz -= 1
        return val

if __name__=="__main__":
    q = CircularQueue(3)
    q.enqueue(1); q.enqueue(2); q.enqueue(3)
    print(q.dequeue())

# Task: Design circular queue
