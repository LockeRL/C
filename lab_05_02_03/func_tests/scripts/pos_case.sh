#!/bin/bash
app_args=""
if [ $# -gt 2 ]; then
    app_args=$3
fi

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind --log-file=log.txt -q ../../app.exe "$1" > script_result.txt
else
   eval ../../app.exe "$1" > script_result.txt 
fi

if ./comparator.sh "$2" ./script_result.txt; then
	exit 0;
else
	exit 1;
fi
