#! /bin/bash
#
gcc -c -Wall -I/$HOME/include constants_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc constants_test.o /$HOME/libc/constants.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm constants_test.o
#
mv a.out constants_test
./constants_test > constants_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm constants_test
#
echo "Normal end of execution."
