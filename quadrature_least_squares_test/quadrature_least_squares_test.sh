#! /bin/bash
#
gcc -c -Wall -I/$HOME/include quadrature_least_squares_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc quadrature_least_squares_test.o /$HOME/libc/quadrature_least_squares.o \
              /$HOME/libc/qr_solve.o \
              /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadrature_least_squares_test.o
#
mv a.out quadrature_least_squares_test
./quadrature_least_squares_test > quadrature_least_squares_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrature_least_squares_test
#
echo "Normal end of execution."
