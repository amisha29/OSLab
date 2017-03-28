#!/bin/bash
echo "Enter directory name : "
read dir1

if [ ! -d $dir1 ]
then
    echo "Invalid directory!"
    exit
fi

large=0;
for file1 in `find $dir1 -type f`
    do
        size1=`stat -c %s $file1`
        echo "Size of $file1 is $size1"
        if [ $size1 -gt $large ]
        then
            large=$size1
            large_file=$file1
        fi
    done

echo "LArgest file : $large_file"
echo "Size : $large"