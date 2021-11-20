#! /bin/bash
#
gcc -c -Wall -I/$HOME/include rkf45_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc rkf45_test.o /$HOME/libc/rkf45.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rkf45_test.o
#
mv a.out rkf45_test
./rkf45_test > rkf45_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rkf45_test
#
echo "Normal end of execution."
