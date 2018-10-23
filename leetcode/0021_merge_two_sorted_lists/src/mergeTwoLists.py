#!/usr/bin/env python3.7


from dataclasses import dataclass


@dataclass
class ListNode:
    val: int
    next = None


class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = cur = ListNode(-1)
        while l1 and l2:
            if l1.val < l2.val:
                node, l1 = l1, l1.next
            else:
                node, l2 = l2, l2.next
            cur.next = node
            cur = cur.next
        cur.next = l1 or l2
        return head.next
