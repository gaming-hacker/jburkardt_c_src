#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ranlib_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ranlib_test.o /$HOME/libc/ranlib.o /$HOME/libc/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ranlib_test.o
#
mv a.out ranlib_test
./ranlib_test > ranlib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ranlib_test
#
echo "Normal end of execution."
