#! /bin/bash
#
cp random_sorted.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include random_sorted.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv random_sorted.o ~/libc/random_sorted.o
#
echo "Normal end of execution."
