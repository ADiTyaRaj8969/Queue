"""
Task: Producer-consumer simulation using queue and threading.Condition
Time Complexity: Depends on workload
Space Complexity: O(n)
"""

import threading
from collections import deque
import time

q = deque()
cond = threading.Condition()
done = False


def producer():
    global done
    for i in range(1,6):
        with cond:
            q.append(i)
            print('produced', i)
            cond.notify()
        time.sleep(0.1)
    with cond:
        done = True
        cond.notify_all()


def consumer(cid):
    while True:
        with cond:
            while not q and not done:
                cond.wait()
            if q:
                v = q.popleft(); print('consumer',cid,'consumed',v)
            elif done:
                break

if __name__=="__main__":
    t1 = threading.Thread(target=producer); t2 = threading.Thread(target=consumer, args=(1,)); t1.start(); t2.start(); t1.join(); t2.join()

# Task: Producer consumer using queue
