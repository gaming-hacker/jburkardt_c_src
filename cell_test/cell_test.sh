#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cell_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cell_test.o /$HOME/libc/cell.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cell_test.o
#
mv a.out cell_test
./cell_test > cell_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cell_test
#
echo "Normal end of execution."
