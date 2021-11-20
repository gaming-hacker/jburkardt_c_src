#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas2_d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas2_d_test.o $HOME/libc/blas2_d.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas2_d_test.o
#
mv a.out blas2_d_test
./blas2_d_test > blas2_d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas2_d_test
#
echo "Normal end of execution."
