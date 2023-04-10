#!/bin/bash
gcc main.c -c -Wall -Werror -std=c99 --coverage -o app.o
gcc app.o -o app.exe --coverage -lm
