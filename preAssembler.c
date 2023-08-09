#include "preAssembler.h"
#include "actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 80

int preAssembler() {
    FILE *postMacro;
    char processedAsProgram[] = "macroProcessed/testProgram1_processed.as";
    char line[MAX_CHAR];
    int linesCount = 0;

    //Reading the post macro processing file
    postMacro = fopen(processedAsProgram, "r");
    //Checking if empty or not
    if(postMacro == NULL) {
        printf("Could not open macro processed program in AsInput %s\n", processedAsProgram);
        return 1;
    }

    printf("Reading in preAssembler: \n");

    //Reading the file line by line
    while(fgets(line, MAX_CHAR, postMacro) != NULL) {
        //printf("%s", line); //Printing the .as file


        /*
         * WE WILL DO LABELS LATER
         *
         * Opcode is the first phrase that is detected each line.
         * Therefore we will detect it first
         */

        //Detecting OPcode using a comparison array

        char comparisonArray[4]; // Array to hold 3 characters plus the null terminator
        int comparisonArrayLen = 0;

        char compareChar;

        //Creating an array that will contain the action(mov, sub, add...)
        for(compareChar = 'a'; compareChar <= 'c'; compareChar++) {
            if(comparisonArrayLen < 3) {
                comparisonArray[comparisonArrayLen] = line[comparisonArrayLen]; // Add the character
                comparisonArrayLen++;
            } else {
                break; // Stop if the array is full
            }
        }

        //test print to see if it works
        printf("Compare array: %s\n", comparisonArray);

        int i;
        for (i = 0; i < 16; i++) {
            if (strcmp(comparisonArray, actions[i]) == 0) {
                printf("Found a match with action element %d: %s\n", i, actions[i]);
            }
        }

        //Comparing the array that we have created to the action table, and seeing what fits




        linesCount++; // Increment the line count
    }

    // Closing the file
    fclose(postMacro);

    printf("\n Lines: %d \n", linesCount);

    return 0;
}







