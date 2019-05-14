#!/bin/bash

win_size=`tput cols`
if [ $win_size -le 122 ]
then
	file="ascii_art"
elif [ $win_size -le 201 ]
then
	file="ascii_art2"
else
	file="ascii_art3"
fi

count=`cat count.txt`
count=`echo $count'+1' | bc`;
echo $count > count.txt

weigth=`cat $file | wc -c | bc`
block=`echo $weigth'/'$1 | bc`;
part=`echo $block'*'$count | bc`;
head -c $part $file | tail -c $block

