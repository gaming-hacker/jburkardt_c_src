#! /bin/bash
#
gcc -c -Wall -I$HOME/include linpack_d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc linpack_d_test.o $HOME/libc/linpack_d.o $HOME/libc/blas1_d.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_d_test.o
#
mv a.out linpack_d_test
./linpack_d_test > linpack_d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linpack_d_test
#
echo "Normal end of execution."
