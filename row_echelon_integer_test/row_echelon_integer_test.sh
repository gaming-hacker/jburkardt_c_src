#! /bin/bash
#
gcc -c -Wall -I/$HOME/include row_echelon_integer_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o row_echelon_integer_test row_echelon_integer_test.o /$HOME/libc/row_echelon_integer.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm row_echelon_integer_test.o
#
./row_echelon_integer_test > row_echelon_integer_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm row_echelon_integer_test
#
echo "Normal end of execution."
