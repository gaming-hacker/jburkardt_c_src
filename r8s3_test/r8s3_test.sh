#! /bin/bash
#
gcc -c -Wall -I/$HOME/include r8s3_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o r8s3_test r8s3_test.o /$HOME/libc/r8s3.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm r8s3_test.o
#
./r8s3_test > r8s3_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8s3_test
#
echo "Normal end of execution."
