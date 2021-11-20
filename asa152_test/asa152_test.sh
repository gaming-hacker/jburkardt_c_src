#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa152_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa152_test.o /$HOME/libc/asa152.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa152_test.o
#
mv a.out asa152_test
./asa152_test > asa152_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa152_test
#
echo "Normal end of execution."
