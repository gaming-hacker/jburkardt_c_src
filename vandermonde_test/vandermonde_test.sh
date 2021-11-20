#! /bin/bash
#
gcc -c -Wall -I/$HOME/include vandermonde_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc vandermonde_test.o /$HOME/libc/vandermonde.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm vandermonde_test.o
#
mv a.out vandermonde_test
./vandermonde_test > vandermonde_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm vandermonde_test
#
echo "Normal end of execution."
