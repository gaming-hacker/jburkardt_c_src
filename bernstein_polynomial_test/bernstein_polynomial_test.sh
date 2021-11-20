#! /bin/bash
#
gcc -c -Wall -I/$HOME/include bernstein_polynomial_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc bernstein_polynomial_test.o /$HOME/libc/bernstein_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bernstein_polynomial_test.o
#
mv a.out bernstein_polynomial_test
./bernstein_polynomial_test > bernstein_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bernstein_polynomial_test
#
echo "Normal end of execution."
