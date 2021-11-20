#! /bin/bash
#
gcc -c -Wall -I/$HOME/include wtime_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc wtime_test.o /$HOME/libc/wtime.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wtime_test.o
#
mv a.out wtime_test
./wtime_test > wtime_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wtime_test
#
echo "Normal end of execution."
