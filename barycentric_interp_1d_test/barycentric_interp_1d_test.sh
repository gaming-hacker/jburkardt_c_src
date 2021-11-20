#! /bin/bash
#
gcc -c -Wall -I/$HOME/include barycentric_interp_1d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc barycentric_interp_1d_test.o /$HOME/libc/barycentric_interp_1d.o \
                                /$HOME/libc/test_interp_1d.o \
                                /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm barycentric_interp_1d_test.o
#
mv a.out barycentric_interp_1d_test
./barycentric_interp_1d_test > barycentric_interp_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm barycentric_interp_1d_test
#
echo "Normal end of execution."
