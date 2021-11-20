#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r83_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o r83_test r83_test.o /$HOME/libc/r83.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm r83_test.o
#
./r83_test > r83_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r83_test
#
echo "Normal end of execution."
