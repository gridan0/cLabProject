#include "macroRead.h"
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 80
#define MACRO_NAME_SPACE 5 //Takes into account the phrase 'mcro' and a space.

int macroRead() {
    //Reading the raw input file, before the macros have been processed.
    FILE *file, *outputFile;
    char rawAsProgram[] = "assemblyPrograms/testProgram1.as";
    char processedAsProgram[] = "macroProcessed/testProgram1_processed.as";
    char line[MAX_CHAR];
    char macroName[MAX_CHAR - MACRO_NAME_SPACE];
    int isMacro = 0;  /* Flag to mark if we are inside a macro */

    file = fopen(rawAsProgram, "r");
    if(file == NULL) {
        printf("Could not open raw assembly program %s\n", rawAsProgram);
        return 1;
    }

    outputFile = fopen(processedAsProgram, "w");
    if(outputFile == NULL) {
        printf("Could not open output file %s\n", processedAsProgram);
        return 1;
    }

    /* Read the file line by line */
    while (fgets(line, MAX_CHAR, file) != NULL) {
        /* Check if the line begins a macro */
        if (strncmp(line, "mcro", 4) == 0) {
            /* Read the macro name from the line */
            if (sscanf(line, "mcro %s", macroName) == 1) {
                printf("Macro name: %s\n", macroName);
                isMacro = 1;
            }
            continue;  /* Skip to next line */
        }

        /* Check if the line ends a macro */
        if (strncmp(line, "endmcro", 7) == 0) {
            isMacro = 0;
            continue;  /* Skip to next line */
        }

        /* If we are inside a macro, we can process the line here */
        if (isMacro) {
            /* Implement your macro processing code here */
            printf("Processing macro line: %s\n", line);
        }

        /* Write the line to the output file */
        fputs(line, outputFile);
    }

    fclose(file);
    fclose(outputFile);
    return 0;
}



