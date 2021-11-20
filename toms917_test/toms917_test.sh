#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms917_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o toms917_test toms917_test.o /$HOME/libc/toms917.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms917_test.o
#
./toms917_test > toms917_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms917_test
#
echo "Normal end of execution."
