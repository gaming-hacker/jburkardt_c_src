#! /bin/bash
#
gcc -c -Wall -I $HOME/include pbmlib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pbmlib_test.o /$HOME/libc/pbmlib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pbmlib_test.o
#
mv a.out pbmlib_test
./pbmlib_test > pbmlib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pbmlib_test
#
echo "Normal end of execution."
