#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o triangle_integrals_test triangle_integrals_test.o /$HOME/libc/triangle_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_integrals_test.o
#
./triangle_integrals_test > triangle_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_integrals_test
#
echo "Normal end of execution."
