#!/bin/bash

i=0
for j in $@
do
  arg[i]=$j
  i=$((i+1))
done

i=0
while [ $i -lt $# ]
do
  cal ${arg[i]} ${arg[i+1]}
  i=$((i+2))
done
