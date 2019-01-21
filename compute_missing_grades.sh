#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <grades file>"
    exit
fi

while read line ; do
    missing=0
    for i in {3..50} ; do
        if [[ `echo $line | cut -f$i -d","` = "NA" ]] ; then
            ((missing++))
        fi
    done
    first_name=`echo $line | cut -f1 -d","`
    last_name=`echo $line | cut -f2 -d","`
    echo "$first_name $last_name: $missing"
done < $1
