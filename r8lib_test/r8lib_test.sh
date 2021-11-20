#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r8lib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o r8lib_test r8lib_test.o /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm r8lib_test.o
#
./r8lib_test > r8lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8lib_test
#
echo "Normal end of execution."
