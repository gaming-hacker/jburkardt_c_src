#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cyclic_reduction_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cyclic_reduction_test.o /$HOME/libc/cyclic_reduction.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cyclic_reduction_test.o
#
mv a.out cyclic_reduction_test
./cyclic_reduction_test > cyclic_reduction_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cyclic_reduction_test
#
echo "Normal end of execution."
