#! /bin/bash
#
cp hermite_product_polynomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hermite_product_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_product_polynomial.o ~/libc/hermite_product_polynomial.o
#
echo "Normal end of execution."
