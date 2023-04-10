#!/bin/bash
for file in *.c;
do 
    gcc -std=c99 -Wall -Werror -O2 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -ggdb -c "$file"
done
string=''
for file in *.o;
do
    string+="$file "
done
eval gcc -o app.exe "$string" -lm
