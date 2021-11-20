#! /bin/bash
#
cp legendre_shifted_polynomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include legendre_shifted_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv legendre_shifted_polynomial.o ~/libc/legendre_shifted_polynomial.o
#
echo "Normal end of execution."
