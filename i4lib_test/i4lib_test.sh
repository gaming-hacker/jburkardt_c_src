#! /bin/bash
#
gcc -c -Wall -I/$HOME/include i4lib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc i4lib_test.o /$HOME/libc/i4lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm i4lib_test.o
#
mv a.out i4lib_test
./i4lib_test > i4lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm i4lib_test
#
echo "Normal end of execution."
