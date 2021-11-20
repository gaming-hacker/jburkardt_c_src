#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa144_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa144_test.o /$HOME/libc/asa144.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa144_test.o
#
mv a.out asa144_test
./asa144_test > asa144_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa144_test
#
echo "Normal end of execution."
