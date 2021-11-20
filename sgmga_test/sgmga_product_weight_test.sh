#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sgmga_product_weight_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sgmga_product_weight_test.o /$HOME/libc/sgmga.o \
                               /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sgmga_product_weight_test.o
#
mv a.out sgmga_product_weight_test
./sgmga_product_weight_test > sgmga_product_weight_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sgmga_product_weight_test
#
echo "Normal end of execution."
