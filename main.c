#include <stdio.h>
#include "macroRead.h" // Include the correct header file
#include "preAssembler.h"

int main() {

    int macroReadCalling = macroRead(); // Call the correct function

    if(macroReadCalling == 1) {
        printf("There was an error reading the file from main");
        return 1;
    }

    int asInputCalling = preAssembler();

    if(asInputCalling == 1) {
        printf("There was an error opening the file.\n");
        return 1;
    }


    return 0;
}

