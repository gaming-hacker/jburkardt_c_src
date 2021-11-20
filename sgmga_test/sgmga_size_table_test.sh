#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sgmga_size_table_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sgmga_size_table_test.o /$HOME/libc/sgmga.o \
                       /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sgmga_size_table_test.o
#
mv a.out sgmga_size_table_test
./sgmga_size_table_test > sgmga_size_table_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sgmga_size_table_test
#
echo "Normal end of execution."
