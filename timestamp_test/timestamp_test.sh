#! /bin/bash
#
gcc -c -Wall -I/$HOME/include timestamp_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc timestamp_test.o /$HOME/libc/timestamp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm timestamp_test.o
#
mv a.out timestamp_test
./timestamp_test > timestamp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm timestamp_test
#
echo "Normal end of execution."
