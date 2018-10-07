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

struct ListNode * rotateRight(struct ListNode * head, int k);

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode head = { .val = 1, .next = NULL};
    rotateRight(&head, 1);
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
