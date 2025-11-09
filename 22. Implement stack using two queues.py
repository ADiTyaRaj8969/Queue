"""
Task: Implement stack using two queues
Time Complexity: push O(n) or pop O(n) depending on approach
Space Complexity: O(n)
"""

from collections import deque

class MyStack:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x):
        self.q1.append(x)

    def pop(self):
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        val = self.q1.popleft()
        self.q1, self.q2 = self.q2, self.q1
        return val

    def top(self):
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        val = self.q1.popleft()
        self.q2.append(val)
        self.q1, self.q2 = self.q2, self.q1
        return val

    def empty(self):
        return not self.q1

if __name__ == "__main__":
    s = MyStack()
    s.push(1); s.push(2); print(s.top()); print(s.pop()); print(s.empty())

# Task: Implement stack using two queues
