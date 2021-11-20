#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r8row_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o r8row_test r8row_test.o /$HOME/libc/r8row.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8row_test.o
#
./r8row_test > r8row_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8row_test
#
echo "Normal end of execution."
