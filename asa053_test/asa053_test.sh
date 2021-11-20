#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa053_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa053_test.o -L $HOME/libc -lasa053 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa053_test.o
#
mv a.out asa053_test
./asa053_test > asa053_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa053_test
#
echo "Normal end of execution."
