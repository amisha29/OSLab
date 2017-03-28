#!/bin/bash
if [ $# -eq 0 ]
then
    echo "Can't have 0 args"
    exit
else
    for login in $*
        do
            if grep $login /etc/passwd > /dev/null
            then
                echo "Login : $login"
                dir=`grep $login /etc/passwd | cut -d ":" -f 6`
                echo "Home directory: $dir"
            else
                echo "Invalid lofin id!"
            fi
        done
fi            