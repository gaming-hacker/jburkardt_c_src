#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_min_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_min_test.o /$HOME/libc/test_min.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_min_test.o
#
mv a.out test_min_test
./test_min_test > test_min_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_min_test
#
echo "Normal end of execution."
