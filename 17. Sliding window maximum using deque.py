"""
Task: Sliding window maximum (wrapper duplicate) — already present as 10, kept for indexing parity
Time Complexity: O(n)
Space Complexity: O(k)
"""

from collections import deque


def sliding_max(a, k):
    dq = deque()
    res = []
    for i, v in enumerate(a):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and a[dq[-1]] <= v:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            res.append(a[dq[0]])
    return res

if __name__ == "__main__":
    a=[1,3,-1,-3,5,3,6,7]
    print(sliding_max(a,3))

# Task: Sliding window maximum using deque (duplicate)
