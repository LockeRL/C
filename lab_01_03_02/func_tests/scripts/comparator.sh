#!/bin/bash

file1="$1"
file2="$2"

test_numbers=$(grep -Eo "(-?)[0-9][0-9]*(\.?)[0-9]*"  "$file1")
right_numbers=$(grep -Eo "(-?)[0-9][0-9]*(\.?)[0-9]*"  "$file2")

if [ "$test_numbers" = "$right_numbers" ]; then
	exit 0;
else
	exit 1;
fi

