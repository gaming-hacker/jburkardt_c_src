#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_interpolate_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o triangle_interpolate_test triangle_interpolate_test.o /$HOME/libc/triangle_interpolate.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_interpolate_test.o
#
./triangle_interpolate_test > triangle_interpolate_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_interpolate_test
#
echo "Normal end of execution."
