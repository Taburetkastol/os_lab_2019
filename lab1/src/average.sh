#!/bin/bash
echo "There are $# arguments"
sum=0
avg=0
mod=0
for i in "$@"
do
sum=$(($sum+$i))
done
avg=$(($sum/$#))
mod=$(($sum%$#))
if [ "$mod" = "0" ]
then echo $avg
else echo $avg "+" $(($sum % $#))"/"$#
fi