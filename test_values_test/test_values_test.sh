#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_values_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_values_test.o /$HOME/libc/test_values.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm test_values_test.o
#
mv a.out test_values_test
./test_values_test > test_values_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_values_test
#
echo "Normal end of execution."
