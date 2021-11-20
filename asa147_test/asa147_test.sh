#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa147_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa147_test.o /$HOME/libc/asa147.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa147_test.o
#
mv a.out asa147_test
./asa147_test > asa147_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa147_test
#
echo "Normal end of execution."
