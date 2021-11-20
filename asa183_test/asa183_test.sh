#! /bin/bash
#
gcc -c -Wall -I $HOME/include asa183_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc asa183_test.o /$HOME/libc/asa183.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa183_test.o
#
mv a.out asa183_test
./asa183_test > asa183_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa183_test
#
echo "Normal end of execution."
