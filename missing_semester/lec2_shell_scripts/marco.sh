#!/bin/bash

marco() {
	export MARCO_DIR="$(pwd)"
	echo "Current directory saved: $MARCO_DIR"
}

polo() {
	if [ -z "$MARCO_DIR" ]; then
		echo "MARCO_DIR is not set :("
	else
		cd "$MARCO_DIR" || echo "failed"
	fi
}
