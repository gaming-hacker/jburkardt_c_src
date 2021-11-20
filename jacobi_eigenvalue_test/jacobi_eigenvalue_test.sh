#! /bin/bash
#
gcc -c -Wall -I/$HOME/include jacobi_eigenvalue_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc jacobi_eigenvalue_test.o /$HOME/libc/jacobi_eigenvalue.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm jacobi_eigenvalue_test.o
#
mv a.out jacobi_eigenvalue_test
./jacobi_eigenvalue_test > jacobi_eigenvalue_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm jacobi_eigenvalue_test
#
echo "Normal end of execution."
