#! /bin/bash
#
gcc -c -Wall -I/$HOME/include mgs_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o mgs_test mgs_test.o /$HOME/libc/mgs.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mgs_test.o
#
./mgs_test > mgs_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm mgs_test
#
echo "Normal end of execution."
