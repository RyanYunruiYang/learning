#!/bin/bash

mcd () {
	mkdir -p "$1"
	cd "$1"
}

mcd hello
# foobar
