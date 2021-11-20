#! /bin/bash
#
gcc -c -Wall -I/$HOME/include exactness_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc exactness_test.o /$HOME/libc/exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm exactness_test.o
#
mv a.out exactness_test
./exactness_test > exactness_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm exactness_test
#
echo "Normal end of execution."
