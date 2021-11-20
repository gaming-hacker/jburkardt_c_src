#! /bin/bash
#
gcc -c -Wall -I/$HOME/include interp_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc interp_test.o /$HOME/libc/interp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm interp_test.o
#
mv a.out interp_test
./interp_test > interp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm interp_test
#
echo "Normal end of execution."
