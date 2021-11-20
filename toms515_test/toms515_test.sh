#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms515_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o toms515_test toms515_test.o /$HOME/libc/toms515.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms515_test.o
#
./toms515_test > toms515_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms515_test
#
echo "Normal end of execution."
