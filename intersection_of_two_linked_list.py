# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        a_len=self.getLength(headA)
        b_len=self.getLength(headB)
        
        a_ptr, b_ptr=headA, headB
        
        if a_len>b_len:
            for i in range(a_len-b_len):
                a_ptr=a_ptr.next
        else:
            for i in range(b_len-a_len):
                b_ptr=b_ptr.next
        while a_ptr and b_ptr:
            if a_ptr==b_ptr:
                return a_ptr
            a_ptr=a_ptr.next
            b_ptr=b_ptr.next
        return None    
    
    def getLength(self, node: ListNode) -> int:
        _len = 0
        cur = node
        while cur:
            cur = cur.next
            _len += 1
        return _len