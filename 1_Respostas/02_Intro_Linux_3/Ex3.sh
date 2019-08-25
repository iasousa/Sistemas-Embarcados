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
  date -d "${arg[i]}/${arg[i+1]}/${arg[i+2]}"
  i=$((i+3))
done
