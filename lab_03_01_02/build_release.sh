#!/bin/bash
gcc -c main.c -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o
gcc -o app.exe main.o -lm

