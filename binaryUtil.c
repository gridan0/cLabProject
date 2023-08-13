
#include "binaryUtil.h"
#include <stdio.h>

/*
 * A function that calculates binary numbers
 */



#include "binaryUtil.h"
#include <stdio.h>
#include <stdlib.h>

void calc10bitnum(const char* numberStr) {
    int number = atoi(numberStr); /* Convert the number string to an integer */
    unsigned int mask = 1 << 9;

    //print result
    printf("10-bit form of %d: ", number);

    int i;
    for(i = 0; i < 10; i++) {
        if (number & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
}

