#! /bin/bash
#
gcc -c -Wall -I/$HOME/include pwl_interp_2d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pwl_interp_2d_test.o /$HOME/libc/pwl_interp_2d.o \
                        /$HOME/libc/test_interp_2d.o \
                        /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pwl_interp_2d_test.o
#
mv a.out pwl_interp_2d_test
./pwl_interp_2d_test > pwl_interp_2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pwl_interp_2d_test
#
echo "Normal end of execution."
