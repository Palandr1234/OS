#!/bin/sh
if test ! -f ex2.txt
then
    echo 0 > ex2.txt
fi
i=1
while [ $i -le 100 ]
do
    if ln ex2.txt ex2.txt.lock
    then
        NUMBER=$(tail -n 1 < ex2.txt)
        expr $NUMBER + 1 >> ex2.txt
        rm ex2.txt.lock
        i=$(($i+1))
    fi
done