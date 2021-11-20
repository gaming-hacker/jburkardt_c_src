#! /bin/bash
#
gcc -c -Wall -I/$HOME/include rnglib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc rnglib_test.o /$HOME/libc/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rnglib_test.o
#
mv a.out rnglib_test
./rnglib_test > rnglib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rnglib_test
#
echo "Normal end of execution."
