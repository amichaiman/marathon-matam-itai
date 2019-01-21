#!/bin/bash

if [[ $# -ne 2 ]] ; then
    echo "Usage: $0 <filename> <pattern>"
    exit
fi

if [[ ! -f $1 ]] ; then
    echo "$1 must be a file"
    exit
fi

while read line ; do
    if [[ $line =~ $2 ]] ; then
        echo $line
    fi
done < $1
