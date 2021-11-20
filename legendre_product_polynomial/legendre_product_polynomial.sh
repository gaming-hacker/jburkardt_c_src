#! /bin/bash
#
cp legendre_product_polynomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include legendre_product_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv legendre_product_polynomial.o ~/libc/legendre_product_polynomial.o
#
echo "Normal end of execution."
