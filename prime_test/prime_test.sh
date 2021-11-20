#! /bin/bash
#
gcc -c -Wall -I/$HOME/include prime_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc prime_test.o /$HOME/libc/prime.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm prime_test.o
#
mv a.out prime_test
./prime_test > prime_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm prime_test
#
echo "Normal end of execution."
