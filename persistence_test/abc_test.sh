#! /bin/bash
#
gcc -c -Wall -I/$HOME/include abc_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc abc_test.o /$HOME/libc/abc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm abc_test.o
#
mv a.out abc_test
./abc_test > abc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm abc_test
#
echo "Normal end of execution."
