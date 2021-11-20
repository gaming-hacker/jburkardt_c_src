#! /bin/bash
#
gcc -c -Wall -I/$HOME/include nintlib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc nintlib_test.o /$HOME/libc/nintlib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm nintlib_test.o
#
mv a.out nintlib_test
./nintlib_test > nintlib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm nintlib_test
#
echo "Normal end of execution."
