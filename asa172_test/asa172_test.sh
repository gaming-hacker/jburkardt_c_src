#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa172_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa172_test.o /$HOME/libc/asa172.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa172_test.o
#
mv a.out asa172_test
./asa172_test > asa172_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa172_test
#
echo "Normal end of execution."
