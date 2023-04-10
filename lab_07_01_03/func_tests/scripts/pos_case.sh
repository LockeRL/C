#!/bin/bash

args=""
if [ $# -gt 1 ]; then
    args="$(cat "$2")"
fi

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind --log-file=log.txt -q ../../app.exe "$args"
else
   eval ../../app.exe "$args"
fi

if ./comparator.sh "$1" ../../out/pos_res.txt; then
	exit 1;
else
	exit 0;
fi
