#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms243_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o toms243_test toms243_test.o /$HOME/libc/toms243.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm toms243_test.o
#
./toms243_test > toms243_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms243_test
#
echo "Normal end of execution."
