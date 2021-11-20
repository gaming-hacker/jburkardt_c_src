#! /bin/bash
#
gcc -c -Wall -I/$HOME/include asa314_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa314_test.o /$HOME/libc/asa314.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa314_test.o
#
mv a.out asa314_test
./asa314_test > asa314_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa314_test
#
echo "Normal end of execution."
