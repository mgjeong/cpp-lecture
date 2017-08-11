#!/bin/sh

if [ $# -eq 0 ]; then
	echo "no target.."
	exit 0
fi

target="SConstruct.$1"

scons -c -f $target

exit 0

