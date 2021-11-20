#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa063_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa063_test.o -L $HOME/libc -lasa063 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa063_test.o
#
mv a.out asa063_test
./asa063_test > asa063_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa063_test
#
echo "Normal end of execution."
