stty -echo
trap " " 15 9 2 1 3 20 30 
echo "Enter the password"
read passwrd1
echo "Confirm password"
read passwrd2
if [ $passwrd1 = $passwrd2 ]
then
    echo "Terminal is locked"
    while true
    do
        stty -echo
        echo "Enter password to unlock : "
        read passwrd3
        if [ $passwrd1 = $passwrd3 ]
        then
            echo "Terminal is unlocked"
            stty echo
            exit
        else
            echo "Incorrect password. Try again"
        fi
    done
else
    echo "passwords don't match'"
    stty echo
fi