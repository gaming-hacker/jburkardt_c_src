#! /bin/bash
#
gcc -c -Wall -I/$HOME/include besselj_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o besselj_test besselj_test.o /$HOME/libc/besselj.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm besselj_test.o
#
./besselj_test > besselj_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm besselj_test
#
echo "Normal end of execution."
