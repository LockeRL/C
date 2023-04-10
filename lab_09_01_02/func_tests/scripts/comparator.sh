#!/bin/bash

get_data()
{
	data=""
	counter=0
	
	for word in $1; do
		if [ ! \( "$word" = "Result:" \) ]; then
			if [ "$counter" = "0" ]; then
				data="$word"
				counter=1
			else
				data="$data $word"
			fi
		fi
	done
	echo "$data"
}


file1="$1"
file2="$2"

check_data=$(cat "$file2")
right_data="Result: $(cat "$file1")"

new_data=$(get_data "$check_data")
new_right_data=$(get_data "$right_data")

if [ "$new_data" = "$new_right_data" ]; then
	exit 0
else
	exit 1
fi
