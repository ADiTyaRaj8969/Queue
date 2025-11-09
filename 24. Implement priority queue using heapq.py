"""
Task: Demonstrate priority queue operations using heapq
Time Complexity: push/pop O(log n)
Space Complexity: O(n)
"""

import heapq

class MinPQ:
    def __init__(self):
        self._data = []

    def push(self, x):
        heapq.heappush(self._data, x)

    def pop(self):
        return heapq.heappop(self._data)

    def top(self):
        return self._data[0]

if __name__=="__main__":
    pq = MinPQ(); pq.push(3); pq.push(1); pq.push(2)
    print(pq.pop()); print(pq.top())

# Task: Implement priority queue using heapq
