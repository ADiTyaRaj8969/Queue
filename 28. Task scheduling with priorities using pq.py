"""
Task: Task scheduling with priorities using heapq
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

import heapq


def schedule(tasks):
    # tasks: list of (priority, name)
    pq = []
    for p,n in tasks:
        heapq.heappush(pq, (-p, n))
    while pq:
        p,n = heapq.heappop(pq)
        print(n, 'with priority', -p)

if __name__=="__main__":
    schedule([(10,'A'), (5,'B'), (20,'C')])

# Task: Task scheduling with priorities using pq
