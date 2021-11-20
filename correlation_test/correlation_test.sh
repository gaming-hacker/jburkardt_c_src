#! /bin/bash
#
gcc -c -Wall -I/$HOME/include correlation_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc correlation_test.o ~/libc/correlation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm correlation_test.o
#
mv a.out correlation_test
./correlation_test > correlation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm correlation_test
#
echo "Normal end of execution."
