#! /bin/bash
#
gcc -c -Wall -I$HOME/include asa091_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa091_test.o -L $HOME/libc -lasa091 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa091_test.o
#
mv a.out asa091_test
./asa091_test > asa091_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa091_test
#
echo "Normal end of execution."
