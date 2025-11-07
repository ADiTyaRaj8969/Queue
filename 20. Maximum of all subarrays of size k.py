"""
Task: Maximum of all subarrays of size k (sliding window maximum)
Time Complexity: O(n)
Space Complexity: O(k)
"""

from collections import deque


def max_subarrays(a, k):
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
    print(max_subarrays([1,3,-1,-3,5,3,6,7], 3))

# Task: Maximum of all subarrays of size k
