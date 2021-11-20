#! /bin/bash
#
gcc -c -Wall -I/$HOME/include normal_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc normal_test.o /$HOME/libc/normal.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm normal_test.o
#
mv a.out normal_test
./normal_test > normal_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm normal_test
#
echo "Normal end of execution."
