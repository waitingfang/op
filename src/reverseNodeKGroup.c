//
//  main.c
//  reverse node in k group
//
//  Created by fzw on 10/12/18.
//  Copyright © 2018 n. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode * reverseKGroup(struct ListNode * head, int k);
void reverse(struct ListNode ** p, struct ListNode ** s);

int main(int argc, const char * argv[]) {
    struct ListNode l5 = {.val=5, .next=NULL};
    struct ListNode l4 = {.val=4, .next=&l5};
    struct ListNode l3 = {.val=3, .next=&l4};
    struct ListNode l2 = {.val=2, .next=&l3};
    struct ListNode l1 = {.val=1, .next=&l2};
    reverseKGroup(&l1, 3);
    return 0;
}

struct ListNode * reverseKGroup(struct ListNode * head, int k) {
    struct ListNode *s, *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    int len = k;
    p->next = head;
    head = p;
    s = p;
    
    while (k-- && s != NULL) {
        s = s->next;
    }
    while (s!=NULL) {
        reverse(&p, &s);
        k = len;
        while (k-- && s!=NULL) {
            s = s->next;
        }
    }
    return head->next;
}

void reverse(struct ListNode ** p, struct ListNode ** s) {
    struct ListNode * prev = (*p)->next, * tmp, * tail = (*p)->next, * flag = (*s)->next;
    (*p)->next = NULL;
    while (prev!=flag) {
        tmp = (*p)->next;
        (*p)->next = prev;
        prev = prev->next;
        (*p)->next->next = tmp;
    }
    
    tail->next = prev;
    *p = tail;
    *s = tail;
}
