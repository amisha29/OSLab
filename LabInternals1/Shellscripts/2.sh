#!/bin/bash
if [ $# -lt 2 ] || [ $# -gt 2 ]
then
    echo "Incorrect num of args"
    exit
else 
    f1=`ls -l $1|cut -c2-10`
    f2=`ls -l $2|cut -c2-10`
    if [ $f1 = $f2 ]
    then
        echo "Same file permissions"
        echo "$f1"
    else
        echo "Different file permissions"
        echo "1st file : $f1"
        echo "2nd file : $f2"
    fi
fi
