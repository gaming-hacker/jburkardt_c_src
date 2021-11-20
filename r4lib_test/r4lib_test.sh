#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r4lib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc r4lib_test.o /$HOME/libc/r4lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r4lib_test.o
#
mv a.out r4lib_test
./r4lib_test > r4lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r4lib_test
#
echo "Normal end of execution."
