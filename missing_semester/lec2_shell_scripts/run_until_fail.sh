#!/bin/bash


count=0

while true; do
	((counter++))
	./random_fail > stdout.txt 2> stderr.txt
	
	if [[ $? -ne 0 ]]; then
		echo "Standard Output: "
		cat stdout.txt
		echo "\n Standard Error: "
		cat  stderr.txt
		

		echo "failed after $counter runs"
		break
	fi
done
