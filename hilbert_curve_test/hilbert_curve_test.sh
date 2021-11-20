#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hilbert_curve_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o hilbert_curve_test hilbert_curve_test.o /$HOME/libc/hilbert_curve.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hilbert_curve_test.o
#
./hilbert_curve_test > hilbert_curve_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hilbert_curve_test
#
echo "Normal end of execution."
