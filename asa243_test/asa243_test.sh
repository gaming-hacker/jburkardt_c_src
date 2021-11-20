#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa243_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa243_test.o /$HOME/libc/asa243.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa243_test.o
#
mv a.out asa243_test
./asa243_test > asa243_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa243_test
#
echo "Normal end of execution."
