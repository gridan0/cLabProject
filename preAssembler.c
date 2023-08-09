#include "preAssembler.h"
#include "actions.h"
#include <stdio.h>

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
        printf("%s", line); //Printing the .as file
        linesCount++; // Increment the line count
    }

    // Closing the file
    fclose(postMacro);

    printf("\n Lines: %d \n", linesCount);

    return 0;
}







