"""
Task: Josephus problem implemented with queue
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import deque


def josephus(n, k):
    dq = deque(range(1, n+1))
    while len(dq) > 1:
        dq.rotate(- (k-1))
        dq.popleft()
    return dq[0]

if __name__ == "__main__":
    print(josephus(7, 3))  # expected 4

# Task: Josephus problem using queue
