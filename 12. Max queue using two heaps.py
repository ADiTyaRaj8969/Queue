"""
Task: Maintain a max-queue (get max in O(1)) using two heaps
Time Complexity: enqueue O(log n), dequeue O(log n), get_max O(1)
Space Complexity: O(n)
"""

import heapq

class MaxQueue:
    def __init__(self):
        self._min_heap = []  # store (id, value) for normal order
        self._max_heap = []  # store (-value, id) for max
        self._counter = 0

    def enqueue(self, x):
        heapq.heappush(self._min_heap, (self._counter, x))
        heapq.heappush(self._max_heap, (-x, self._counter))
        self._counter += 1

    def dequeue(self):
        if not self._min_heap:
            raise IndexError("dequeue from empty")
        idx, val = heapq.heappop(self._min_heap)
        # lazy deletion in max_heap
        while self._max_heap and self._max_heap[0][1] < idx:
            heapq.heappop(self._max_heap)
        return val

    def get_max(self):
        while self._max_heap and self._max_heap[0][1] < (self._counter - len(self._min_heap)):
            heapq.heappop(self._max_heap)
        if not self._max_heap:
            raise IndexError("empty")
        return -self._max_heap[0][0]

if __name__ == "__main__":
    mq = MaxQueue()
    mq.enqueue(1)
    mq.enqueue(3)
    mq.enqueue(2)
    print(mq.get_max())
    print(mq.dequeue())

# Task: Max queue using two heaps
