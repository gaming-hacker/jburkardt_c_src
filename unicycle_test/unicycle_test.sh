#! /bin/bash
#
gcc -c -Wall -I/$HOME/include unicycle_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc unicycle_test.o /$HOME/libc/unicycle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm unicycle_test.o
#
mv a.out unicycle_test
./unicycle_test > unicycle_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm unicycle_test
#
echo "Normal end of execution."
