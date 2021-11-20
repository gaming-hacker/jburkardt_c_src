#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_approx_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_approx_test.o /$HOME/libc/test_approx.o \
                      /$HOME/libc/spline.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_approx_test.o
#
mv a.out test_approx_test
./test_approx_test > test_approx_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm  test_approx_test
#
echo "Normal end of execution."
