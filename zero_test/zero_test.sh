#! /bin/bash
#
gcc -c -Wall -I/$HOME/include zero_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc zero_test.o /$HOME/libc/zero.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm zero_test.o
#
mv a.out zero_test
./zero_test > zero_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm zero_test
#
echo "Normal end of execution."
