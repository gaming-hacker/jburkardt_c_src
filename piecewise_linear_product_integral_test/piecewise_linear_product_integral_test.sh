#! /bin/bash
#
gcc -c -Wall -I/$HOME/include piecewise_linear_product_integral_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc piecewise_linear_product_integral_test.o /$HOME/libc/piecewise_linear_product_integral.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm piecewise_linear_product_integral_test.o
#
mv a.out piecewise_linear_product_integral_test
./piecewise_linear_product_integral_test > piecewise_linear_product_integral_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm piecewise_linear_product_integral_test
#
echo "Normal end of execution."
