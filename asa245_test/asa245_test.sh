#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa245_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa245_test.o /$HOME/libc/asa245.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa245_test.o
#
mv a.out asa245_test
./asa245_test > asa245_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa245_test
#
echo "Normal end of execution."
