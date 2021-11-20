#! /bin/bash
#
cp piecewise_linear_product_integral.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include piecewise_linear_product_integral.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv piecewise_linear_product_integral.o ~/libc/piecewise_linear_product_integral.o
#
echo "Normal end of execution."
