#include "preAssembler.h"
#include "actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryUtil.h"
#include "firstOperand.h"

#define MAX_CHAR 80
#define NUMBER_OF_ACTIONS 16

int preAssembler() {
    FILE *postMacro;
    char processedAsProgram[] = "macroProcessed/testProgram1_processed.as";
    char line[MAX_CHAR];
    int linesCount = 0;
    int registerFlag = 0;
    char* originOperand = readNumbersInstruction(line,&registerFlag);


    //Miun types
    char miun1[] = "001";
    char miun3[] = "011";
    char miun5[] = "101";

    /*
     * Legal operands, two stages
     */


    //Reading the post macro processing file
    postMacro = fopen(processedAsProgram, "r");
    //Checking if empty or not
    if(postMacro == NULL) {
        printf("Could not open macro processed program in AsInput %s\n", processedAsProgram);
        return 1;
    }

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

        //Comparing the array that we have created to the action table, and seeing what fits
        int count1;
        for (count1 = 0; count1 < NUMBER_OF_ACTIONS; count1++) {
            if (strcmp(comparisonArray, actions[count1]) == 0) {
                //If the action from the .as file matches the action we detected

                //We should get the bit value of comparisonArray
                printf("The machine code for %s, is %s \n ", comparisonArray, actions_bit[count1]);

                //Let's print the instruction word, only with the opcode, without the operands

                char instruction_word[13]; //OUR INSTRUCTION WORD
                // Initialize instruction_word with zeros
                memset(instruction_word, '0', sizeof(instruction_word) - 1); // -1 to leave space for null terminator

                // Null-terminate the instruction_word string
                instruction_word[12] = '\0';

                //Position of the opcode in the instruction word
                int opcodePosition = 3;
                int count2;
                // Copy the values from comparisonArray into instruction_word at the desired position
                for (count2 = 0; count2 < strlen(actions_bit[count1]); count2++) {
                    // Insert the array pos of comparisonArray with the value of actionBit
                    instruction_word[opcodePosition + count2] = actions_bit[count1][count2];
                }

                /*
                 * Checking MIUN ORIGIN OPERAND
                 */

                //Checking to see if the origin operand is a number
                if(readNumbersInstruction(line,&registerFlag) != NULL) {
                    //Here we have detected that there's content in the operand.
                    //IF it's a number, it's MIUN1(mi'un miyadi)
                    //IF it's a register, it's MIUN5(mi'un oger)
                    int originOperandMiunPos = 0;
                    if(registerFlag == 0) {
                        //MIUN MIYADI
                        //Pasting the miun code into the instruction word
                        strncpy(instruction_word + originOperandMiunPos, miun1, 3);
                        calc10bitnum(readNumbersInstruction(line,&registerFlag));
                        printf("instruction_word: %s\n", instruction_word);

                        /*
                         * INFORMATION WORD needs to be added to the output
                         * it will contain the number itself
                         */
                        // Initialize firstInfoWord with zeros, and null terminate
                        char firstInfoWord[13];
                        memset(firstInfoWord, '0', sizeof(firstInfoWord) - 1);
                        firstInfoWord[12] = '\0';

                        // Calculate the 10-bit binary number using calc10bitnum
                        char* firstInfoWordValue = calc10bitnum(readNumbersInstruction(line, &registerFlag));

                        // Copy the 10-bit binary number into firstInfoWord, starting at position 0, leaving the two rightmost digits as zeros
                        strncpy(firstInfoWord, firstInfoWordValue, 10);
                        // Free the dynamically allocated memory for firstInfoWordValue
                        free(firstInfoWordValue);
                        // Print the result
                        printf("1st info word:  %s \n", firstInfoWord);

                    } else if(registerFlag == 1) {
                        //MIUN OGER (MIUN 5)
                        strncpy(instruction_word + originOperandMiunPos, miun5, 3);
                        printf("instruction_word: %s\n", instruction_word);
                    }
                }
            }
        }
        linesCount++; // Increment the line count
    }

    // Closing the file
    fclose(postMacro);
    printf("\n Lines: %d \n", linesCount);

    return 0;
}







