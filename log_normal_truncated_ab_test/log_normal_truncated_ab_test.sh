#! /bin/bash
#
gcc -c -Wall -I/$HOME/include log_normal_truncated_ab_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o log_normal_truncated_ab_test log_normal_truncated_ab_test.o /$HOME/libc/log_normal_truncated_ab.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm log_normal_truncated_ab_test.o
#
./log_normal_truncated_ab_test > log_normal_truncated_ab_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm log_normal_truncated_ab_test
#
echo "Normal end of execution."
