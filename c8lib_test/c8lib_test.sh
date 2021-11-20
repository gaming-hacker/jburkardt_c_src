#! /bin/bash
#
gcc -c -Wall -I/$HOME/include c8lib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc c8lib_test.o /$HOME/libc/c8lib.o /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm c8lib_test.o
#
mv a.out c8lib_test
./c8lib_test > c8lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c8lib_test
#
echo "Normal end of execution."
