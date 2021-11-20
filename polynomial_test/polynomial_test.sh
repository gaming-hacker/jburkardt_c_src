#! /bin/bash
#
gcc -c -Wall -I/$HOME/include polynomial_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polynomial_test.o /$HOME/libc/polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polynomial_test.o
#
mv a.out polynomial_test
./polynomial_test > polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polynomial_test
#
echo "Normal end of execution."
