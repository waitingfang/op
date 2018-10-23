//
//  main.c
//  addBinary
//
//  Created by fzw on 10/7/18.
//  Copyright © 2018 n. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * addBinary(char * a, char * b);

int main(int argc, const char * argv[]) {
    char * a = "11";
    char * b = "11";
    printf("%s\n", addBinary(a, b));
    return 0;
}

char * addBinary(char * a, char * b) {
    int i, lenA, lenB, len, temp = 0;
    char * str;
    lenA = (int)strlen(a);
    lenB = (int)strlen(b);
    len = lenA > lenB ? lenA: lenB;
    str = (char *)malloc((len+2)*sizeof(char));
    memset(str, 0, (len+2)*sizeof(char));
    
    for (i = len; i >= 0 && lenA > 0 && lenB > 0; i--) {
        *(str+i) = ((*(a + lenA-1) - '0') + (*(b + lenB-1) - '0') + temp)%2 + '0';
        temp = ((*(a + lenA-1) - '0') + (*(b + lenB-1) - '0') + temp)/2;
        lenA--;
        lenB--;
    }
    
    if (lenA == 0) {
        for (; lenB > 0; i--) {
            *(str+i) = ((*(b + lenB-1) - '0') + temp) % 2 + '0';
            temp = ((*(b + lenB-1) - '0') + temp)/ 2;
            lenB--;
        }
    } else if (lenB == 0) {
        for (; lenA > 0; i--) {
            *(str+i) = ((*(a + lenA-1) - '0') + temp) % 2 + '0';
            temp = ((*(a + lenA-1) - '0') + temp) / 2;
            lenA--;
        }
    }
    if (temp == 1) {
        *(str+i) = temp + '0';
        return str + i;
    }
    
    return str + i + 1;
}
