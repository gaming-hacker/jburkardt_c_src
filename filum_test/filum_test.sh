#! /bin/bash
#
gcc -c -Wall -I/$HOME/include filum_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc filum_test.o /$HOME/libc/filum.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm filum_test.o
#
mv a.out filum_test
./filum_test > filum_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm filum_test
#
echo "Normal end of execution."
