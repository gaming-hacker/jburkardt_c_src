#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas1_d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas1_d_test.o $HOME/libc/blas1_d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas1_d_test.o
#
mv a.out blas1_d_test
./blas1_d_test > blas1_d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas1_d_test
#
echo "Normal end of execution."
