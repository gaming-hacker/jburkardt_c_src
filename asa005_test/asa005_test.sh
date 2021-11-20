#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa005_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa005_test.o -L $HOME/libc -lasa005 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa005_test.o
#
mv a.out asa005_test
./asa005_test > asa005_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa005_test
#
echo "Normal end of execution."
