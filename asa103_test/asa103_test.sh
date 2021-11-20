#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa103_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa103_test.o -L $HOME/libc -lasa103 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa103_test.o
#
mv a.out asa103_test
./asa103_test > asa103_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa103_test
#
echo "Normal end of execution."
