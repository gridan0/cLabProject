
#include "binaryUtil.h"
#include <stdio.h>

/*
 * A function that calculates binary numbers
 */



#include "binaryUtil.h"
#include <stdio.h>
#include <stdlib.h>

char* calc10bitnum(const char* numberStr) {
    int number = atoi(numberStr);
    unsigned int mask = 1 << 9;
    char* binaryStr = (char*)malloc(11 * sizeof(char)); // 10 bits + null terminator

    int i;
    for(i = 0; i < 10; i++) {
        if (number & mask) {
            binaryStr[i] = '1';
        } else {
            binaryStr[i] = '0';
        }
        mask >>= 1;
    }
    binaryStr[10] = '\0'; // Null-terminate the string

    return binaryStr;
}

