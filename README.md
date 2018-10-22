# data structure; algorithm

1. merge two sorted array

   [implement by c](./src/MergeTwoSortedArray.c)
   
2. [narcissistic number](http://acm.hdu.edu.cn/showproblem.php?pid=2010)

   [implement by c](./src/narcissisticNumber.c)

3. [Rotate List](https://leetcode.com/problems/rotate-list/)

   [implement by c](./src/rotateList.c)

   [implement by golang](./src/rotateList.go)
   ```
   Given a linked list, rotate the list to the right by k places, where k is non-negative.
   
   Example 1:
   
   Input: 1->2->3->4->5->NULL, k = 2
   Output: 4->5->1->2->3->NULL
   
   Explanation:
   rotate 1 steps to the right: 5->1->2->3->4->NULL
   rotate 2 steps to the right: 4->5->1->2->3->NULL
   
   Example 2:
   
   Input: 0->1->2->NULL, k = 4
   Output: 2->0->1->NULL
   
   Explanation:
   rotate 1 steps to the right: 2->0->1->NULL
   rotate 2 steps to the right: 1->2->0->NULL
   rotate 3 steps to the right: 0->1->2->NULL
   rotate 4 steps to the right: 2->0->1->NULL
   ```

4. [add Binary](https://leetcode.com/problems/add-binary/)

   [implement by c](./src/addBinary.c)
   
   implement by python
   > bin(int(a, 2) + int(b, 2))[2:]

   ```
   Given two binary strings, return their sum (also a binary string).

   The input strings are both non-empty and contains only characters 1 or 0.

   Example 1:

   Input: a = "11", b = "1"
   Output: "100"
   
   Example 2:

   Input: a = "1010", b = "1011"
   Output: "10101"
   ```
   
5. [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

   [implement by c](./src/reverseNodeKGroup.c)
   
   [implement by go](./src/reverseNodeKGroup.go)

   [implement by py](./src/reverseNodeKGroup.py)
   
   ```
   Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

   k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

   Example:

   Given this linked list: 1->2->3->4->5

   For k = 2, you should return: 2->1->4->3->5

   For k = 3, you should return: 3->2->1->4->5

   Note:

   Only constant extra memory is allowed.
   You may not alter the values in the list's nodes, only nodes itself may be changed.
   
   ```

6. [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

    solution 1 [implement by py](./src/mergeTwoLists.py)

    solution 2 [implement by go](./src/mergeTwoLists.go)
    ```
    Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

    Example:

    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4
    ```
