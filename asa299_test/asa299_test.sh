#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa299_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa299_test.o /$HOME/libc/asa299.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa299_test.o
#
mv a.out asa299_test
./asa299_test > asa299_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa299_test
#
echo "Normal end of execution."
