#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cg_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o cg_test cg_test.o /$HOME/libc/cg.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cg_test.o
#
./cg_test > cg_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cg_test
#
echo "Normal end of execution."
