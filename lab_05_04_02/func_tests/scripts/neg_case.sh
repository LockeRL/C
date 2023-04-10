#!/bin/bash

args="$(cat "$1")"

if [ -n "$USE_VALGRIND" ]; then
	if [ "$2" -eq 4 ]; then
		eval valgrind -q --log-file=log.txt ../../app.exe "$args" < ../data/neg_add.txt > cache.txt
	else
		eval valgrind -q --log-file=log.txt ../../app.exe "$args" > cache.txt
	fi
else
	if [ "$2" -eq 4 ]; then
		eval ../../app.exe "$args" < ../data/neg_add.txt > cache.txt
	else
		eval ../../app.exe "$args" > cache.txt
	fi
fi

if [ $? ]; then
    exit 0
else
    exit 1
fi

