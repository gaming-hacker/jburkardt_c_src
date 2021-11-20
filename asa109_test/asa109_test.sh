#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa109_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa109_test.o /$HOME/libc/asa109.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa109_test.o
#
mv a.out asa109_test
./asa109_test > asa109_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa109_test
#
echo "Normal end of execution."
