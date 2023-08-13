#include <stdio.h>

//Here we will concentrate all of the actions and related operations with them
//Including the binary translation

#define ACTION_KEY 16 //number of actions

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

//Bit translation of actions, corresponding to their position(up to 15 in bits)
//This will be the opcode in the machine
const char *actions_bit[] = {
        "0000",
        "0002",
        "0010",
        "0011",
        "0100",
        "0101",
        "0110",
        "0111",
        "1000",
        "1001",
        "1010",
        "1011",
        "1100",
        "1101",
        "1110",
        "1111"
};

