"""
Task: Circular buffer class for streaming data
Time Complexity: write/read O(1)
Space Complexity: O(k)
"""

class CircularBuffer:
    def __init__(self, capacity):
        self.buf = [None]*capacity
        self.cap = capacity
        self.head = 0
        self.tail = 0
        self.size = 0

    def write(self, data):
        # write a single item, overwrite oldest when full
        if self.size == self.cap:
            # overwrite oldest
            self.buf[self.tail] = data
            self.tail = (self.tail+1)%self.cap
            self.head = self.tail
        else:
            self.buf[self.tail] = data
            self.tail = (self.tail+1)%self.cap
            self.size += 1

    def read(self):
        if self.size==0:
            raise IndexError("read from empty buffer")
        val = self.buf[self.head]
        self.buf[self.head] = None
        self.head = (self.head+1)%self.cap
        self.size -= 1
        return val

if __name__=="__main__":
    cb = CircularBuffer(3)
    cb.write(1); cb.write(2); cb.write(3)
    cb.write(4)  # overwrites oldest
    while cb.size>0:
        print(cb.read())

# Task: Circular buffer for streaming data
