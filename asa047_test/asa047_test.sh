#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa047_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa047_test.o -L $HOME/libc -lasa047 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa047_test.o
#
mv a.out asa047_test
./asa047_test > asa047_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa047_test
#
echo "Normal end of execution."
