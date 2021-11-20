#! /bin/bash
#
gcc -c -Wall -I/$HOME/include bank_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o bank_test bank_test.o /$HOME/libc/bank.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bank_test.o
#
./bank_test > bank_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bank_test
#
echo "Normal end of execution."
