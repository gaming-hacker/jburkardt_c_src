#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sine_transform_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sine_transform_test.o /$HOME/libc/sine_transform.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sine_transform_test.o
#
mv a.out sine_transform_test
./sine_transform_test > sine_transform_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sine_transform_test
#
echo "Normal end of execution."
