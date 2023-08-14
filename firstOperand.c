//
// Created by betsa on 12/08/2023.
//

#include "firstOperand.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CHAR 80

/* Detecting numbers on the 4th position (would need to account for the stop action) */
#define NUMBER_TO_DETECT_POS 4

char* readNumbersInstruction(const char line[MAX_CHAR]) {
    int startPos = NUMBER_TO_DETECT_POS; /* Starting from position 5 */
    int i = startPos;
    int j = 0;
    char* number = (char*)malloc(MAX_CHAR * sizeof(char));

    /* Initialize the number to empty string */
    number[0] = '\0';

    /* Looking for a number */
    while (line[i] != ',' && line[i] != '\0') {
        if (isdigit((unsigned char)line[i])) {
            /* Collecting digits into a number string */
            while (isdigit((unsigned char)line[i]) && line[i] != ',' && line[i] != '\0') {
                number[j++] = line[i++];
            }
            number[j] = '\0'; /* Null terminate the number string */
            return number;
        }
        i++;
    }

    printf("No number detected.\n");
    free(number);
    return NULL;
}
