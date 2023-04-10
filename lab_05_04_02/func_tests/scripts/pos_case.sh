#!/bin/bash

args="$(cat "$1")"

if [ -n "$USE_VALGRIND" ]; then
	if [ "$3" -le 3 ]; then
    	eval valgrind --log-file=log.txt -q ../../app.exe "$args"
    	if cmp -s "$2" "./0${3}_out.txt" ; then
    		exit 0;
    	else
    		exit 1;
    	fi
    elif [ "$3" -le 7 ]; then
    	eval valgrind --log-file=log.txt -q ../../app.exe "$args" < ../data/add_0"$3".txt
    	if cmp -s "$2" "$4" ; then
    		exit 0;
    	else
    		exit 1;
    	fi
    else
    	eval valgrind --log-file=log.txt -q ../../app.exe "$args" > script_result.txt
    	if ./comparator.sh "$2" ./script_result.txt; then
			exit 0;
		else
			exit 1;
		fi
    fi
else
	if [ "$3" -le 3 ]; then
    	eval ../../app.exe "$args"
    	if cmp -s "$2" "./0${3}_out.txt" ; then
    		exit 0;
    	else
    		exit 1;
    	fi
    elif [ "$3" -le 7 ]; then
    	eval ../../app.exe "$args" < ../data/add_0"$3".txt
    	if cmp -s "$2" "$4" ; then
    		exit 0;
    	else
    		exit 1;
    	fi
    else
    	eval "../../app.exe $args" > script_result.txt
    	if ./comparator.sh "$2" ./script_result.txt; then
			exit 0;
		else
			exit 1;
		fi
    fi
fi

