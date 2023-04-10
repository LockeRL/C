#!/bin/bash

if [ -n "$USE_VALGRIND" ]; then
	eval valgrind -q --log-file=../../out/log.txt ../../app.exe < "$1" > ../../out/script_result_neg.txt
else
	eval ../../app.exe < "$1" > ../../out/script_result_neg.txt
fi

if ./comparator.sh "$2" ../../out/script_result_neg.txt; then
	exit 0;
else
	exit 1;
fi

