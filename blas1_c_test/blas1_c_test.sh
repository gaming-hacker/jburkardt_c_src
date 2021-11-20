#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas1_c_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas1_c_test.o $HOME/libc/blas1_c.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas1_c_test.o
#
mv a.out blas1_c_test
./blas1_c_test > blas1_c_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas1_c_test
#
echo "Normal end of execution."
