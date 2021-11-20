#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa121_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa121_test.o /$HOME/libc/asa121.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa121_test.o
#
mv a.out asa121_test
./asa121_test > asa121_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa121_test
#
echo "Normal end of execution."
