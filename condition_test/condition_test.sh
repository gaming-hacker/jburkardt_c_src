#! /bin/bash
#
gcc -c -Wall -I/$HOME/include condition_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc condition_test.o /$HOME/libc/condition.o /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm condition_test.o
#
mv a.out condition_test
./condition_test > condition_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm condition_test
#
echo "Normal end of execution."
