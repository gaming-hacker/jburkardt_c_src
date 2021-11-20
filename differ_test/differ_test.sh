#! /bin/bash
#
gcc -c -Wall -I/$HOME/include differ_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc differ_test.o /$HOME/libc/differ.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm differ_test.o
#
mv a.out differ_test
./differ_test > differ_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm differ_test
#
echo "Normal end of execution."
