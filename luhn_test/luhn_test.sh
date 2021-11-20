#! /bin/bash
#
gcc -c -Wall -I/$HOME/include luhn_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o luhn_test luhn_test.o /$HOME/libc/luhn.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm luhn_test.o
#
./luhn_test > luhn_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm luhn_test
#
echo "Normal end of execution."
