#! /bin/bash
#
gcc -c -Wall -I/$HOME/include spline_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc spline_test.o /$HOME/libc/spline.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm spline_test.o
#
mv a.out spline_test
./spline_test > spline_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm spline_test
#
echo "Normal end of execution."
