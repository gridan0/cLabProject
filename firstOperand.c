#include "firstOperand.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CHAR 80

#define NUMBER_TO_DETECT_POS 4

char* readNumbersInstruction(const char line[MAX_CHAR], int* registerFlag) {
    int startPos = NUMBER_TO_DETECT_POS;
    int i = startPos;
    int j = 0;
    char* operandContent = (char*)malloc(MAX_CHAR * sizeof(char));
    *registerFlag = 0; // Reset the flag to 0

    /* Initialize the operandContent to empty string */
    operandContent[0] = '\0';

    while (line[i] != ',' && line[i] != '\0') {



        if (isdigit((unsigned char)line[i])) {
            /* Collecting digits into a operandContent string */
            while (isdigit((unsigned char)line[i]) && line[i] != ',' && line[i] != '\0') {
                operandContent[j++] = line[i++];
            }
            operandContent[j] = '\0'; /* Null terminate the operandContent string */
            return operandContent;
            /*
             * DETECTING REGISTER AND IT'S NUMBER
             */
        } else if (line[i] == '@' && line[i + 1] == 'r' && isdigit(line[i + 2]) && line[i + 2] >= '0' && line[i + 2] <= '7') {
            /* Collecting the character after @r */

            //If register is detected, flag will turn into 1.
            *registerFlag = 1;

            operandContent[j++] = line[i + 2];
            operandContent[j] = '\0'; /* Null terminate the operandContent string */
            printf("Register detected \n");

            return operandContent;
        }
        i++;
    }

    free(operandContent);
    return NULL;
}
