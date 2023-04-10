#!/bin/bash

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind --log-file=../../out/log.txt -q ../../app.exe < "$1" > ../../out/script_result.txt
else
   eval ../../app.exe < "$1" > ../../out/script_result.txt
fi

if ./comparator.sh "$2" ../../out/script_result.txt; then
	exit 0;
else
	exit 1;
fi
