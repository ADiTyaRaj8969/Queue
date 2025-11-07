"""
Task: Merge K sorted arrays using a min-heap
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq


def merge_k_arrays(lists):
    pq = []
    for i, arr in enumerate(lists):
        if arr:
            heapq.heappush(pq, (arr[0], i, 0))
    res = []
    while pq:
        val, i, j = heapq.heappop(pq)
        res.append(val)
        if j+1 < len(lists[i]):
            heapq.heappush(pq, (lists[i][j+1], i, j+1))
    return res

if __name__ == "__main__":
    print(merge_k_arrays([[1,4,5],[1,3,4],[2,6]]))

# Task: Merge k sorted arrays using pq
