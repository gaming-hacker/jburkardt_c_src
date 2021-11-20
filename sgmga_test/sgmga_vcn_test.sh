#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sgmga_vcn_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sgmga_vcn_test.o /$HOME/libc/sgmga.o\
                    /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sgmga_vcn_test.o
#
mv a.out sgmga_vcn_test
./sgmga_vcn_test > sgmga_vcn_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sgmga_vcn_test
#
echo "Normal end of execution."
