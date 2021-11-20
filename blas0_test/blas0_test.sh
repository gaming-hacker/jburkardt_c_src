#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas0_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas0_test.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas0_test.o
#
mv a.out blas0_test
./blas0_test > blas0_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas0_test
#
echo "Normal end of execution."
