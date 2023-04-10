#!/bin/bash
gcc -c main.c -Wall  -Wpedantic -Wextra -ggdb
gcc -o app.exe main.o -lm
