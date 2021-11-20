#! /bin/bash
#
gcc -c -Wall dot_product.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc dot_product.o -pthread
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm dot_product.o
mv a.out dot_product
./dot_product > dot_product.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm dot_product
#
echo "Normal end of execution."
