#!/bin/bash
#
gcc -c -Wall -I/$HOME/include triangle01_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle01_integrals_test.o /$HOME/libc/triangle01_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle01_integrals_test.o
#
mv a.out triangle01_integrals_test
./triangle01_integrals_test > triangle01_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle01_integrals_test
#
echo "Normal end of execution."
