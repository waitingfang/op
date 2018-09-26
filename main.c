//
//  main.c
//  MergeSortedArray
//
//  Created by fzw on 9/26/18.
//  Copyright © 2018 n. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int *, int, int *, int);

int main(int argc, const char * argv[]) {
    int a[] = {1,3,4,7,12,13,17,43,52,110};
    int b[] = {0,2,4,5,6,9,44};
    merge(b, 7, a, 10);
    return 0;
}

void merge(int* nums1, int m, int* nums2, int n) {
    if (m <= 0 || n <= 0) {
        return;
    }
    
    int * c = (int *)malloc(sizeof(int) * (m+n));
    memset(c, 0, sizeof(int) * (m+n));
    
    int i = 0, j = 0, k = 0;
    while (j < m && k < n) {
        if (nums1[j] < nums2[k]) {
            c[i] = nums1[j];
            j++;
        } else {
            c[i] = nums2[k];
            k++;
        }
        i++;
    }
    
    if (j == m) {  // nums1 first end.
        for (; k < n; k++) {
            c[i] = nums2[k];
            i++;
        }
    } else if (k == n) {  // nums2 first end.
        for (; j < m; j++) {
            c[i] = nums1[j];
            i++;
        }
    }
    
    printf("merge result is:\n");
    for (int l = 0; l < i; l++) {
        printf("%d ", c[l]);
    }
    printf("\n");
    free(c);
}
