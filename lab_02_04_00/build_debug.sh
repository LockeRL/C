#!/bin/bash
gcc -c main.c -Wall -Werror -Wpedantic -Wextra -ggdb
gcc -o app.exe main.o -lm
