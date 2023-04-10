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
	if ./pos_case.sh ../data/args_${counter}_pos.txt ../data/pos_${counter}_out.txt "$number" ../data/pos_${counter}_in.txt; then
		echo "Positive test $counter passed"
	else
		echo "Positive test $counter failed"
	fi
done

echo
number=0
neg_files=$(find ../data -type f -name "neg_*_in.txt")
for file in $neg_files; do 
	number=$((number + 1))
	if [ "$number" -lt 10 ]; then
		counter="0$number"
	else
		counter=$number
	fi
	echo "$file" > cache.txt
	if ./neg_case.sh ../data/args_${counter}_neg.txt "$number"; then
		echo "Negative test $counter passed"
	else
		echo "Negative test $counter failed"
	fi
done
exit 0

