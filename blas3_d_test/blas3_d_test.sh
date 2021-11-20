#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas3_d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas3_d_test.o $HOME/libc/blas3_d.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas3_d_test.o
#
mv a.out blas3_d_test
./blas3_d_test > blas3_d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas3_d_test
#
echo "Normal end of execution."
