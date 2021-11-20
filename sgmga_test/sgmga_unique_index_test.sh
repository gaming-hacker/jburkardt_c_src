#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sgmga_unique_index_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sgmga_unique_index_test.o /$HOME/libc/sgmga.o \
                             /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sgmga_unique_index_test.o
#
mv a.out sgmga_unique_index_test
./sgmga_unique_index_test > sgmga_unique_index_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sgmga_unique_index_test
#
echo "Normal end of execution."
