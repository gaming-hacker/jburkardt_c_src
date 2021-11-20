#! /bin/bash
#
gcc -c -Wall -I/$HOME/include change_making_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o change_making_test change_making_test.o /$HOME/libc/change_making.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm change_making_test.o
#
./change_making_test > change_making_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm change_making_test
#
echo "Normal end of execution."
