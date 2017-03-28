#!/bin/bash
echo "Enter 1st num : "
read a
echo "Enter 2nd num : "
read b
echo "Enter 3rd num : "
read c
if [ $a -gt $b ]
then
    if [ $a -gt $c ]
    then
        echo "$a is greatest"
    else
        echo "$c is greatest"
    fi
else
    if [ $b -gt $c ]
    then
        echo "$b is greatest"
    else
        echo "$c is greatest"
    fi
fi