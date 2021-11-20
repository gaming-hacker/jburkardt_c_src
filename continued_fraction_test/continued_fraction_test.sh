#! /bin/bash
#
gcc -c -Wall -I/$HOME/include continued_fraction_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o continued_fraction_test continued_fraction_test.o /$HOME/libc/continued_fraction.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm continued_fraction_test.o
#
./continued_fraction_test > continued_fraction_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm continued_fraction_test
#
echo "Normal end of execution."
