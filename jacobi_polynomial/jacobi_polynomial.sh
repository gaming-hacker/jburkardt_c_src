#! /bin/bash
#
cp jacobi_polynomial.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include jacobi_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv jacobi_polynomial.o ~/libc/jacobi_polynomial.o
#
echo "Normal end of execution."
