#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa032_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa032_test.o -L $HOME/libc -lasa032 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa032_test.o
#
mv a.out asa032_test
./asa032_test > asa032_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa032_test
#
echo "Normal end of execution."
