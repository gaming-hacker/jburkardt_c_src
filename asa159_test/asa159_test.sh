#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa159_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa159_test.o /$HOME/libc/asa159.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa159_test.o
#
mv a.out asa159_test
./asa159_test > asa159_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa159_test
#
echo "Normal end of execution."
