#!/bin/bash

A=$1
B=$2
LIMIT=$3
SUM=0

for ((n=1; n < $LIMIT; n++))
do
    if [ $((n % $A)) -eq 0 ] || [ $((n % $B)) -eq 0 ]
    then
	SUM=$((SUM + n))
    fi
done

echo $SUM
