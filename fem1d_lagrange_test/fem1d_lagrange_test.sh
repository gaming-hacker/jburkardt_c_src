#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fem1d_lagrange_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o fem1d_lagrange_test fem1d_lagrange_test.o /$HOME/libc/fem1d_lagrange.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem1d_lagrange_test.o
#
./fem1d_lagrange_test > fem1d_lagrange_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem1d_lagrange_test
#
echo "Normal end of execution."
