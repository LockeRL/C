#!/bin/bash

args="$(cat "$1")"

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind --log-file=log.txt -q ../../app.exe "$args"
else
	eval ../../app.exe "$args"
fi

if [ $? ]; then
    exit 0
else
    exit 1
fi

