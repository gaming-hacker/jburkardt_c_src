#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hankel_cholesky_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o hankel_cholesky_test hankel_cholesky_test.o /$HOME/libc/hankel_cholesky.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hankel_cholesky_test.o
#
./hankel_cholesky_test > hankel_cholesky_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hankel_cholesky_test
#
echo "Normal end of execution."
