#!/usr/bin/env python3


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x: int) -> None:
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None or head.next is None or k < 2:
            return head
        
        p = s = ListNode(0)
        l = k
        p.next = head
        head = p

        while s is not None and k != 0:
            s = s.next
            k -= 1

        while s is not None:
            p, s = self.reverse(p, s)
            k = l
            while s is not None and k != 0:
                s = s.next
                k -= 1
        
        return head.next

    def reverse(self, p: ListNode, s: ListNode) -> tuple:
        prev = p.next
        tail = p.next
        tmp = p.next
        flag = s.next

        p.next = None
        while prev is not flag:
            tmp = p.next
            p.next = prev
            prev = prev.next
            p.next.next = tmp
        
        tail.next = prev
        p = tail
        s = tail
        return p, s


def main():
    head = ListNode(1)
    tmp = head
    for i in range(2, 6):
        ne = ListNode(i)
        tmp.next = ne
        tmp = ne
    print(Solution().reverseKGroup(head, 2).val)
    

if __name__ == '__main__':
    main()
