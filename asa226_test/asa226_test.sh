#! /bin/bash
#
gcc -c -Wall -I/$HOME/include asa226_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa226_test.o /$HOME/libc/asa226.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa226_test.o
#
mv a.out asa226_test
./asa226_test > asa226_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa226_test
#
echo "Normal end of execution."
