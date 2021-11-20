#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r8ge_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc r8ge_test.o /$HOME/libc/r8ge.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8ge_test.o
#
mv a.out r8ge_test
./r8ge_test > r8ge_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8ge_test
#
echo "Normal end of execution."
