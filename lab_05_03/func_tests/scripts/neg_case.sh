#!/bin/bash

args="$(cat "$1")"

if [ -n "$USE_VALGRIND" ]; then
	eval valgrind -q --log-file=log.txt ../../app.exe "$args" > cache.txt
else
	eval ../../app.exe "$args" > cache.txt
fi

if [ $? ]; then
    exit 0
else
    exit 1
fi

