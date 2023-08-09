#include <stdio.h>

//Here we will concentrate all of the actions and related operations with them

#define ACTION_KEY 16 //number of actions

//Action types:

//Requires 2 operands:
/*
 * mov 0
 * cmp 1
 * add 2
 * sub 3
 * lea 6
 */


//Requires 1 operand:

/*
 * not 4
 * clr 5
 * inc 7
 * dec 8
 * jmp 9
 * bne 10
 * red 11
 * prn 12
 * jsr 13
 */

//Requires no operand:
/*
 * rts 14
 * stop 15
 */

//Array with all of the actions
const char *actions[ACTION_KEY] = {
        "mov",
        "cmp",
        "add",
        "sub",
        "not",
        "clr",
        "lea",
        "inc",
        "dec",
        "jmp",
        "bne",
        "red",
        "prn",
        "jsr",
        "rts",
        "stop"
};

// Action types that require 2 operands:
const char *actions_two_operands[] = {
        "mov",
        "cmp",
        "add",
        "sub",
        "lea"
};

// Action types that require 1 operand:
const char *actions_one_operand[] = {
        "not",
        "clr",
        "inc",
        "dec",
        "jmp",
        "bne",
        "red",
        "prn",
        "jsr"
};

// Action types that require no operands:
const char *actions_no_operands[] = {
        "rts",
        "stop"
};