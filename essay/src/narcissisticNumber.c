//
//  main.c
//  narcissisticNumber
//
//  Created by fzw on 10/7/18.
//  Copyright © 2018 n. All rights reserved.
//

#include <stdio.h>

void narcissisticNumber(int m, int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    narcissisticNumber(100, 200);
    return 0;
}

void narcissisticNumber(int m, int n) {
    if (m > n) {
        return;
    }
    int flag = 0;
    for (int o = m, i, j, k = 0; o <= n; o++) {
        i = o / 100;
        j = o / 10 % 10;
        k = o % 10;
        if (i*i*i + j*j*j + k*k*k == o) {
            flag = 1;
            printf("%d ", o);
        }
    }
    if (flag == 0) {
        printf("no\n");
    } else {
        printf("\n");
    }
    return;
}
