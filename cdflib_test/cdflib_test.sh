#! /bin/bash
#
gcc -c -Wall -I$HOME/include cdflib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cdflib_test.o $HOME/libc/cdflib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cdflib_test.o
#
mv a.out cdflib_test
./cdflib_test > cdflib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cdflib_test
#
echo "Normal end of execution."
