cmake_minimum_required(VERSION 3.24)
project(AssemblerProject C)

set(CMAKE_C_STANDARD 90)

add_executable(AssemblerProject main.c preAssembler.c preAssembler.h macroRead.c macroRead.h actions.c Assembler.c Assembler.h memory.c memory.h binaryUtil.c binaryUtil.h firstOperand.c firstOperand.h)
