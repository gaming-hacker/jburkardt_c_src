#! /bin/bash
#
gcc -c -Wall -I/$HOME/include vandermonde_approx_1d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc vandermonde_approx_1d_test.o /$HOME/libc/vandermonde_approx_1d.o \
                                /$HOME/libc/test_interp.o \
                                /$HOME/libc/qr_solve.o \
                                /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm vandermonde_approx_1d_test.o
#
mv a.out vandermonde_approx_1d_test
./vandermonde_approx_1d_test > vandermonde_approx_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm vandermonde_approx_1d_test
#
echo "Normal end of execution."
