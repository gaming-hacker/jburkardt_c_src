#! /bin/bash
#
gcc -c -Wall -I/$HOME/include lagrange_interp_1d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc lagrange_interp_1d_test.o /$HOME/libc/lagrange_interp_1d.o \
                             /$HOME/libc/test_interp_1d.o \
                             /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lagrange_interp_1d_test.o
#
mv a.out lagrange_interp_1d_test
./lagrange_interp_1d_test > lagrange_interp_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lagrange_interp_1d_test
#
echo "Normal end of execution."
