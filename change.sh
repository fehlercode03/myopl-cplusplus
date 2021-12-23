#!/bin/bash

if [[ $# -gt 0 ]]
then
	files=$@
	b=0
else
	files=$(ls include)
	b=1
fi

for f in $files
do
	if [[ $b -eq 0 ]]; then a=$f; else a=include/$f; fi
	echo -e "\n// this is a comment to make make think i changed something" >> $a
	#echo $a
done
