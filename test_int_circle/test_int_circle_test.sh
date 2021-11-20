#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_int_circle_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_int_circle_test.o /$HOME/libc/test_int_circle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_int_circle_test.o
#
mv a.out test_int_circle_test
./test_int_circle_test > test_int_circle_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_int_circle_test
#
echo "Normal end of execution."
