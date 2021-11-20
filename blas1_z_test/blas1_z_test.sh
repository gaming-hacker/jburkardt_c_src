#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas1_z_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas1_z_test.o $HOME/libc/blas1_z.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas1_z_test.o
#
mv a.out blas1_z_test
./blas1_z_test > blas1_z_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas1_z_test
#
echo "Normal end of execution."
