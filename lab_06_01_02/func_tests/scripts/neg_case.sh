#!/bin/bash

args="$(cat "$1")"

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind --log-file=log.txt -q ../../app.exe "$args" > script_result_neg.txt
else
	eval ../../app.exe "$args" > script_result_neg.txt 
fi

if [ $? ]; then
    exit 0
else
    exit 1
fi

