#! /bin/bash
#
gcc -c -Wall -I/$HOME/include line_cvt_lloyd_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o line_cvt_lloyd_test line_cvt_lloyd_test.o /$HOME/libc/line_cvt_lloyd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_cvt_lloyd_test.o
#
./line_cvt_lloyd_test > line_cvt_lloyd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_cvt_lloyd_test
#
echo "Normal end of execution."
