#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa241_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa241_test.o /$HOME/libc/asa241.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa241_test.o
#
mv a.out asa241_test
./asa241_test > asa241_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa241_test
#
echo "Normal end of execution."
