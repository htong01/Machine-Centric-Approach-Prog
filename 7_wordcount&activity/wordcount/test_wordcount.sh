#! /bin/bash

# Put whatever tests you want here, e.g., 
# echo "words, words, words" | ./wordcount

./wordcount "words, words, words"
./wordcount README.md
./wordcount activity.tsv
./wordcount README.md -l
./wordcount README.md -w
./wordcount README.md -c

