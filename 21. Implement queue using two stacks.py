"""
Task: Implement queue using two stacks
Time Complexity: amortized O(1) for pop/push
Space Complexity: O(n)
"""

class MyQueue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, x):
        self.s1.append(x)

    def pop(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if not self.s2:
            raise IndexError('pop from empty')
        return self.s2.pop()

    def peek(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if not self.s2:
            raise IndexError('peek from empty')
        return self.s2[-1]

    def empty(self):
        return not self.s1 and not self.s2

if __name__=="__main__":
    q=MyQueue(); q.push(1); q.push(2); print(q.peek()); print(q.pop()); print(q.empty())

# Task: Implement queue using two stacks
