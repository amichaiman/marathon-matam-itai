#!/bin/bash

if [[ $# -ne 1 ]] ; then
    echo "Usage: $0 <folder name>"
    exit
fi

if [[ ! -d $1 ]] ; then
    echo "$1 must be a directory"
fi

max_in_folder=0

for file in $1/* ; do           #iterate over folder
    if [[ -f $file ]] ; then    #make sure it's a file
        max_in_file=0;
        while read line ; do    #iterate over lines in file
            words_in_line=`echo $line | wc -w`
            if [[ $words_in_line -gt max_in_file ]] ; then
                max_in_file=$words_in_line
            fi
        done < $file
        if [[ $max_in_file -gt $max_in_folder ]] ; then
            max_in_folder=$max_in_file
        fi
    fi
done

echo "max in folder is $max_in_folder"
