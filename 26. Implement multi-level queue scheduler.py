"""
Task: Simple multi-level queue scheduler simulation
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import deque

if __name__=="__main__":
    levels = [deque(), deque(), deque()]
    levels[0].append(1); levels[1].append(2); levels[2].append(3); levels[0].append(4)
    for lvl in range(3):
        while levels[lvl]:
            print('processing task', levels[lvl].popleft(), 'at level', lvl)

# Task: Implement multi-level queue scheduler
