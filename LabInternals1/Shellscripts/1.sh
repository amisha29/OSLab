#!/bin/bash
if [ $# -eq 0 ]
then
    echo "Can't have 0 args"
    exit
else
    for token in $*
    do
        rev="$token $rev"
    done
    echo $rev
fi