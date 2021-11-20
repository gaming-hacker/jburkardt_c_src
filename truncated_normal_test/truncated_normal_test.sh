#! /bin/bash
#
gcc -c -Wall -I/$HOME/include truncated_normal_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc truncated_normal_test.o /$HOME/libc/truncated_normal.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm truncated_normal_test.o
#
mv a.out truncated_normal_test
./truncated_normal_test > truncated_normal_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm truncated_normal_test
#
echo "Normal end of execution."
