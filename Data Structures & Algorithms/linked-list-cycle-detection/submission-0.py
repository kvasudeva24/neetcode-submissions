# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head.next
        while slow != fast:
            if fast == None or fast.next == None:
                return False
            else:
                slow = slow.next
                fast = fast.next.next
        
        return True
        