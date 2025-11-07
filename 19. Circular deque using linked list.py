"""
Task: Circular deque using doubly linked list (duplicate of C++ example)
Time Complexity: O(1)
Space Complexity: O(k)
"""

class Node:
    def __init__(self,val):
        self.val=val
        self.prev=None
        self.next=None

class CircularDeque:
    def __init__(self,k):
        self.head=None; self.tail=None; self.cap=k; self.sz=0

    def push_front(self,x):
        if self.sz==self.cap: return False
        n=Node(x)
        if not self.head:
            self.head=self.tail=n
        else:
            n.next=self.head; self.head.prev=n; self.head=n
        self.sz+=1; return True

    def push_back(self,x):
        if self.sz==self.cap: return False
        n=Node(x)
        if not self.tail:
            self.head=self.tail=n
        else:
            self.tail.next=n; n.prev=self.tail; self.tail=n
        self.sz+=1; return True

    def pop_front(self):
        if self.sz==0: return False
        t=self.head; self.head=self.head.next
        if self.head: self.head.prev=None
        else: self.tail=None
        self.sz-=1; return True

    def pop_back(self):
        if self.sz==0: return False
        t=self.tail; self.tail=self.tail.prev
        if self.tail: self.tail.next=None
        else: self.head=None
        self.sz-=1; return True

if __name__=="__main__":
    dq=CircularDeque(3); dq.push_back(1); dq.push_back(2); dq.push_front(0); print('ok')

# Task: Circular deque using linked list
