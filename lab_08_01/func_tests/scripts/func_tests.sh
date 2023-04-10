#!/bin/bash
number=0
pos_files=$(find ../data -type f -name "pos_*_in.txt")
for file in $pos_files; do 
	number=$((number + 1))
	if [ "$number" -lt 10 ]; then
		counter="0$number"
	else
		counter=$number
	fi
	if ./pos_case.sh ../data/pos_${counter}_in.txt ../data/pos_${counter}_out.txt; then
		echo "Positive test $counter passed"
	else
		echo "Positive test $counter failed"
	fi
done

echo
number=0
check_file=''
neg_files=$(find ../data -type f -name "neg_*_in.txt")
for file in $neg_files; do 
	number=$((number + 1))
	if [ "$number" -lt 10 ]; then
		counter="0$number"
	else
		counter=$number
	fi
	echo "$file" > ../../out/cache.txt
	echo "" > ../../out/check.txt
	if [ -f ../data/neg_${counter}_out.txt ]; then
		check_file="../data/neg_${counter}_out.txt"
	else
		check_file="../../out/check.txt"
	fi
	if ./neg_case.sh ../data/neg_${counter}_in.txt "$check_file"; then
		echo "Negative test $counter passed"
	else
		echo "Negative test $counter failed"
	fi
done
exit 0

