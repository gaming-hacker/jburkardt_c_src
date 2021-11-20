#! /bin/bash
#
gcc -c -Wall -I/$HOME/include chebyshev_polynomial_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc chebyshev_polynomial_test.o /$HOME/libc/chebyshev_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm chebyshev_polynomial_test.o
#
mv a.out chebyshev_polynomial_test
./chebyshev_polynomial_test > chebyshev_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm chebyshev_polynomial_test
#
echo "Normal end of execution."
