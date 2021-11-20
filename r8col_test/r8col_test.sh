#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r8col_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o r8col_test r8col_test.o /$HOME/libc/r8col.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8col_test.o
#
./r8col_test > r8col_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8col_test
#
echo "Normal end of execution."
