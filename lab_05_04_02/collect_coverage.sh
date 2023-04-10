#!/bin/bash
for file in *.gcda; 
do
	gcov -r "$file"
done
