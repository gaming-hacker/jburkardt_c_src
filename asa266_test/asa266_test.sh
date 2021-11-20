#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa266_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa266_test.o /$HOME/libc/asa266.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa266_test.o
#
mv a.out asa266_test
./asa266_test > asa266_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa266_test
#
echo "Normal end of execution."
