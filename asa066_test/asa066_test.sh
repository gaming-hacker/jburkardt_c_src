#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa066_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa066_test.o -L $HOME/libc -lasa066 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa066_test.o
#
mv a.out asa066_test
./asa066_test > asa066_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa066_test
#
echo "Normal end of execution."
