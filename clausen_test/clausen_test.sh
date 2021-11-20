#! /bin/bash
#
gcc -c -Wall -I/$HOME/include clausen_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o clausen_test clausen_test.o /$HOME/libc/clausen.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm clausen_test.o
#
./clausen_test > clausen_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm clausen_test
#
echo "Normal end of execution."
