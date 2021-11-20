#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sgmga_point_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sgmga_point_test.o /$HOME/libc/sgmga.o \
                      /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sgmga_point_test.o
#
mv a.out sgmga_point_test
./sgmga_point_test > sgmga_point_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sgmga_point_test
#
echo "Normal end of execution."
