"""
Task: Merge K sorted linked lists using a min-heap
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq

class ListNode:
    def __init__(self, val=0, nxt=None):
        self.val = val
        self.next = nxt

    def __lt__(self, other):
        return self.val < other.val


def merge_k_lists(lists):
    heap = []
    for lst in lists:
        if lst:
            heapq.heappush(heap, (lst.val, lst))
    dummy = ListNode(0)
    cur = dummy
    while heap:
        _, node = heapq.heappop(heap)
        cur.next = node
        cur = cur.next
        if node.next:
            heapq.heappush(heap, (node.next.val, node.next))
    return dummy.next

# small helper to build linked list from list

def build(arr):
    dummy=ListNode(0); cur=dummy
    for x in arr:
        cur.next=ListNode(x); cur=cur.next
    return dummy.next

if __name__=="__main__":
    lists=[build([1,4,5]), build([1,3,4]), build([2,6])]
    merged = merge_k_lists(lists)
    cur=merged
    while cur:
        print(cur.val, end=' ')
        cur=cur.next
    print()

# Task: Merge k sorted linked lists using min-heap
