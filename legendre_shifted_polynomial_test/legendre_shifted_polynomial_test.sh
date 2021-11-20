#! /bin/bash
#
gcc -c -Wall -I/$HOME/include legendre_shifted_polynomial_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o legendre_shifted_polynomial_test legendre_shifted_polynomial_test.o /$HOME/libc/legendre_shifted_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm legendre_shifted_polynomial_test.o
#
./legendre_shifted_polynomial_test > legendre_shifted_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm legendre_shifted_polynomial_test
#
echo "Normal end of execution."
