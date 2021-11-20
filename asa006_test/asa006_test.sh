#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa006_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa006_test.o -L $HOME/libc -lasa006 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa006_test.o
#
mv a.out asa006_test
./asa006_test > asa006_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa006_test
#
echo "Normal end of execution."
