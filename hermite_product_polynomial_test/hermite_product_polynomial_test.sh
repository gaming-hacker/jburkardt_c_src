#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hermite_product_polynomial_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o hermite_product_polynomial_test hermite_product_polynomial_test.o /$HOME/libc/hermite_product_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hermite_product_polynomial_test.o
#
./hermite_product_polynomial_test > hermite_product_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hermite_product_polynomial_test
#
echo "Normal end of execution."
