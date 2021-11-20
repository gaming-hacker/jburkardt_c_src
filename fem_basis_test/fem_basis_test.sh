#! /bin/bash
#
gcc -c -Wall -I/$HOME/include fem_basis_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem_basis_test.o /$HOME/libc/fem_basis.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_basis_test.o
#
mv a.out fem_basis_test
./fem_basis_test > fem_basis_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem_basis_test
#
echo "Normal end of execution."
