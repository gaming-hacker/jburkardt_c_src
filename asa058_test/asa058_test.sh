#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa058_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa058_test.o -L $HOME/libc -lasa058 -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa058_test.o
#
mv a.out asa058_test
./asa058_test > asa058_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa058_test
#
echo "Normal end of execution."
