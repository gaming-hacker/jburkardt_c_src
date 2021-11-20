#! /bin/bash
#
gcc -c -Wall -I/$HOME/include walker_sample_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o walker_sample_test walker_sample_test.o /$HOME/libc/walker_sample.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm walker_sample_test.o
#
./walker_sample_test > walker_sample_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm walker_sample_test
#
echo "Normal end of execution."
