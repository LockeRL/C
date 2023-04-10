#!/bin/bash

args=""
if [ $# -gt 1 ]; then
    args="$(cat "$2")"
fi

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind --log-file=log.txt -q ../../app.exe "$args" > script_result_pos.txt
else
   eval ../../app.exe "$args" > script_result_pos.txt 
fi

if ./comparator.sh "$1" ./script_result_pos.txt; then
	exit 1;
else
	exit 0;
fi
