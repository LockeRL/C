#!/bin/bash
app_args=""
if [ $# -gt 2 ]; then
    app_args=$3
fi

if [ -n "$USE_VALGRIND" ]; then
	eval valgrind -q --log-file=log.txt ../../app.exe "$app_args" < "$1" > script_result_neg.txt
else
	eval ../../app.exe "$app_args" < "$1" > script_result_neg.txt 
fi

if ./comparator.sh "$2" ./script_result_neg.txt; then
	exit 0;
else
	exit 1;
fi

