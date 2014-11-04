#!/bin/bash

for i in *sort
do
	echo $i
	str= $(time ./$i < ../ds/assignment1/input5 | grep "real"| cut -d"." -f1)
	echo $str
	echo -e "\n"
done
