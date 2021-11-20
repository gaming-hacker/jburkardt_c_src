#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_zero_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_zero_test.o /$HOME/libc/test_zero.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_zero_test.o
#
mv a.out test_zero_test
./test_zero_test > test_zero_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_zero_test
#
echo "Normal end of execution."
