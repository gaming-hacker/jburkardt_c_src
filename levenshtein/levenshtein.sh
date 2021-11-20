#! /bin/bash
#
cp levenshtein.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include levenshtein.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv levenshtein.o ~/libc/levenshtein.o
#
echo "Normal end of execution."
