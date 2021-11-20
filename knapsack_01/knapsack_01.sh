#! /bin/bash
#
cp knapsack_01.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include knapsack_01.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv knapsack_01.o ~/libc/knapsack_01.o
#
echo "Normal end of execution."
