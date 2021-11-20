#! /bin/bash
#
gcc -c -Wall -I/$HOME/include padua_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc padua_test.o /$HOME/libc/padua.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm padua_test.o
#
mv a.out padua_test
./padua_test > padua_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm padua_test
#
echo "Normal end of execution."
