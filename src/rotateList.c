//
//  main.c
//  RotateList
//
//  Created by fzw on 10/7/18.
//  Copyright © 2018 n. All rights reserved.
//

#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode * rotateRight(struct ListNode * head, int k);  // 解法一
struct ListNode * rotateRight2(struct ListNode * head, int k);  // 解法二

int main(int argc, const char * argv[]) {
    struct ListNode l2 = {.val = 2, .next = NULL};
    struct ListNode l1 = {.val = 1, .next = &l2};
    rotateRight2(&l1, 2);
    return 0;
}

struct ListNode * rotateRight(struct ListNode * head, int k) {
    /* 首先找出需翻转的位置，同时记录链表长度listsize。
     如果k > listsize， 则k = k % listsize;否则重复翻转。
    */
    if (!head || !head->next || k==0) {
        return head;
    }
    
    int listSize = 0;
    int count = 0;
    struct ListNode * rotateNode = head, * p = head;
    
    while (p && count < k) {
        p = p->next;
        ++listSize;
        ++count;
    }
    if (!p) {
        k = k % listSize;
        if (k == 0) {
            return head;
        }
        p = head;
        count = 0;
        while (count++ < k) {
            p = p->next;
        }
    }
    while (p->next) {
        rotateNode = rotateNode->next;
        p = p->next;
    }
    
    p->next = head;
    head = rotateNode->next;
    rotateNode->next = NULL;
    return head;
}

struct ListNode * rotateRight2(struct ListNode * head, int k) {
    /*先遍历整个链表获得链表长度n，然后把链表头和尾链接起来，再走n - k % n个节点，断开链表即可*/
    if (!head || k == 0 || !head->next) {
        return head;
    }
    
    int listSize = 1;
    struct ListNode * cur = head;
    
    while (cur->next) {
        ++listSize;
        cur = cur->next;
    }
    cur->next = head;
    
    if (k >= listSize) {
        k %= listSize;
        if (k == 0) {
            return head;
        }
    }
    
    int m = listSize - k;
    for (int i = 0; i < m; ++i) {
        cur = cur->next;
    }
    
    head = cur->next;
    cur->next = NULL;
    return head;
}

