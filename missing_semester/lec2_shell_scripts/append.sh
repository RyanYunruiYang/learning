#!/bin/bash

echo "Starting program at $(date)" # date will be substituted

echo "Running program $0 with $# arguments with pid $$"

for file in "$@"; do
	grep foobar "$file" > /dev/null 2> /dev/null
	# This redirects STDOUT and STDERR to a null register
	
	if [[ $? -ne 0 ]]; then
		echo "File $file does not have any foobar, adding one"
		echo "# foobar" >> "$file"
	fi
done
