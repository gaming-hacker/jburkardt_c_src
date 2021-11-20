#! /bin/bash
#
gcc -c -Wall -I/$HOME/include knapsack_01_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o knapsack_01_test knapsack_01_test.o /$HOME/libc/knapsack_01.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm knapsack_01_test.o
#
./knapsack_01_test > knapsack_01_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm knapsack_01_test
#
echo "Normal end of execution."
