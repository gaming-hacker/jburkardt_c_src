#! /bin/bash
#
gcc -c -Wall -I/$HOME/include randlc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc randlc_test.o /$HOME/libc/randlc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm randlc_test.o
#
mv a.out randlc_test
./randlc_test > randlc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm randlc_test
#
echo "Normal end of execution."
