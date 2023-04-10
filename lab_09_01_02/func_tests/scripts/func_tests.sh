#!/bin/bash
number=0
pos_files=$(find ../data -type f -name "pos_*_args.txt")
for file in $pos_files; do 
	number=$((number + 1))
	if [ "$number" -lt 10 ]; then
		counter="0$number"
	else
		counter=$number
	fi
	if ./pos_case.sh ../data/pos_${counter}_out.txt ../data/pos_${counter}_args.txt; then
		echo "Positive test $counter failed"
	else
		echo "Positive test $counter passed"
	fi
done

echo
number=0
neg_files=$(find ../data -type f -name "neg_*_args.txt")
for file in $neg_files; do 
	number=$((number + 1))
	if [ "$number" -lt 10 ]; then
		counter="0$number"
	else
		counter=$number
	fi
	echo "$file" > ../../out/cache.txt
	if ./neg_case.sh ../data/neg_${counter}_args.txt; then
		echo "Negative test $counter passed"
	else
		echo "Negative test $counter failed"
	fi
done
exit 0

