#! /bin/bash
#
gcc -c -Wall -I/$HOME/include log_normal_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc log_normal_test.o /$HOME/libc/log_normal.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm log_normal_test.o
#
mv a.out log_normal_test
./log_normal_test > log_normal_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm log_normal_test
#
echo "Normal end of execution."
