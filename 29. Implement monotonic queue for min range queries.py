"""
Task: Monotonic queue for range min queries
Time Complexity: O(n)
Space Complexity: O(k)
"""

from collections import deque

class MonotonicQueue:
    def __init__(self):
        self.deq = deque()

    def push(self, x):
        while self.deq and self.deq[-1] > x:
            self.deq.pop()
        self.deq.append(x)

    def pop(self, x):
        if self.deq and self.deq[0] == x:
            self.deq.popleft()

    def get_min(self):
        return self.deq[0]

if __name__=="__main__":
    a=[2,1,3,4,6,3,8,9,10,12,56]; k=4
    mq=MonotonicQueue()
    res=[]
    for i,v in enumerate(a):
        mq.push(v)
        if i>=k:
            mq.pop(a[i-k])
        if i>=k-1:
            res.append(mq.get_min())
    print(res)

# Task: Implement monotonic queue
