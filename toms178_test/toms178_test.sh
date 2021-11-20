#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms178_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc toms178_test.o /$HOME/libc/toms178.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms178_test.o
#
mv a.out toms178_test
./toms178_test > toms178_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms178_test
#
echo "Normal end of execution."
