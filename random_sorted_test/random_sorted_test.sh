#! /bin/bash
#
gcc -c -Wall -I/$HOME/include random_sorted_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o random_sorted_test random_sorted_test.o /$HOME/libc/random_sorted.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm random_sorted_test.o
#
./random_sorted_test > random_sorted_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm random_sorted_test
#
echo "Normal end of execution."
