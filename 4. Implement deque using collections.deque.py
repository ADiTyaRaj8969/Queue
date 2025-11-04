"""
Task: Demonstrate deque operations using Python's collections.deque
Time Complexity: O(1) per deque op
Space Complexity: O(n)
"""

from collections import deque

if __name__ == "__main__":
    dq = deque()
    dq.append(1)
    dq.appendleft(0)
    dq.append(2)
    print(dq)  # deque([0,1,2])
    dq.pop()
    dq.popleft()
    print(dq)

# Task: Implement deque using collections.deque
