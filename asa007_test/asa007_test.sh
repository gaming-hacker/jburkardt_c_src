#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa007_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa007_test.o -L $HOME/libc -lasa007 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa007_test.o
#
mv a.out asa007_test
./asa007_test > asa007_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa007_test
#
echo "Normal end of execution."
