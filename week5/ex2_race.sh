#!/bin/sh
if test ! -f ex2.txt
then
    echo 0 > ex2.txt
fi
for i in $(seq 1 100)
do
    NUMBER=$(tail -n 1 < ex2.txt)
    expr $NUMBER + 1 >> ex2.txt
done
# Race condition manifests itself when program prints 1. 
# The part of the program where the shared memory is accessed is called the critical region
#in this case, it is line NUMBER=$(tail -n 1 < ex2.txt)