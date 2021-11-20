#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa111_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa111_test.o /$HOME/libc/asa111.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa111_test.o
#
mv a.out asa111_test
./asa111_test > asa111_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa111_test
#
echo "Normal end of execution."
