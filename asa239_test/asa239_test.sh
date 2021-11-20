#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa239_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa239_test.o /$HOME/libc/asa239.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa239_test.o
#
mv a.out asa239_test
./asa239_test > asa239_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa239_test
#
echo "Normal end of execution."
